//
// Created by dwb on 2022/2/9.
//

#include "Sort.h"

Sort::Sort(QObject *parent) : QObject(parent) {
    KalmanTracker::kf_count = 0;
}

Sort::~Sort() {

}

vector<TrackingBox> Sort::process(vector<TrackingBox> detFrameData) {
    //1.init kalman tackers
    if (trackers.size() == 0) // the first frame met
    {
        // initialize kalman trackers using first detections.
        for (unsigned int i = 0; i < detFrameData.size(); i++) {
            KalmanTracker trk = KalmanTracker(detFrameData[i]);//第fi帧的第i个detbox
            trackers.push_back(trk);
        }
    }

    predictedBoxes.clear();

    //2.predict
    for (auto it = trackers.begin(); it != trackers.end();) {
        Rect_<float> pBox = (*it).predict();//predict
        if (pBox.x >= 0 && pBox.y >= 0) {
            predictedBoxes.push_back(pBox);
            it++;
        } else {
            it = trackers.erase(it);
        }
    }

    // 3.associate detections to tracked object (both represented as bounding boxes)
    // predicted --- detected associate
    // dets : detFrameData[fi]
    trkNum = predictedBoxes.size();
    detNum = detFrameData.size();

    if(trkNum==0 && detNum==0)
    {
        vector<TrackingBox> no;
        return no;
    }

    iouMatrix.clear();
    iouMatrix.resize(trkNum, vector<double>(detNum, 0));

    for (unsigned int i = 0; i < trkNum; i++) // compute iou matrix as a distance matrix
    {
        for (unsigned int j = 0; j < detNum; j++) {
            // use 1-iou because the hungarian algorithm computes a minimum-cost assignment.
            iouMatrix[i][j] = 1 - GetIOU(predictedBoxes[i], detFrameData[j].box);//minus 1 for minimum-cost
        }
    }

    // solve the assignment problem using hungarian algorithm.
    // the resulting assignment is [track(prediction) : detection], with len=preNum
    assignment.clear();
    HungAlgo.Solve(iouMatrix, assignment);

    // find matches, unmatched_detections and unmatched_predictions
    unmatchedTrajectories.clear();
    unmatchedDetections.clear();
    allItems.clear();
    matchedItems.clear();

    if (detNum > trkNum) //	there are unmatched detections
    {
        for (unsigned int n = 0; n < detNum; n++)
            allItems.insert(n);

        for (unsigned int i = 0; i < trkNum; ++i)
            matchedItems.insert(assignment[i]);

        set_difference(allItems.begin(), allItems.end(),
                       matchedItems.begin(), matchedItems.end(),
                       insert_iterator<set<int>>(unmatchedDetections, unmatchedDetections.begin()));
    } else if (detNum < trkNum) // there are unmatched trajectory/predictions
    {
        for (unsigned int i = 0; i < trkNum; ++i)
            if (assignment[i] == -1) // unassigned label will be set as -1 in the assignment algorithm
                unmatchedTrajectories.insert(i);
    }

    // filter out matched with low IOU
    matchedPairs.clear();
    for (unsigned int i = 0; i < trkNum; ++i) {
        if (assignment[i] == -1) // pass over invalid values
            continue;
        if (1 - iouMatrix[i][assignment[i]] < iouThreshold) {
            unmatchedTrajectories.insert(i);
            unmatchedDetections.insert(assignment[i]);
        } else
            matchedPairs.push_back(cv::Point(i, assignment[i]));
    }

    // 4.updating trackers
    // update matched trackers with assigned detections.
    // each prediction is corresponding to a tracker
    int detIdx, trkIdx;
    for (unsigned int i = 0; i < matchedPairs.size(); i++) {
        trkIdx = matchedPairs[i].x;
        detIdx = matchedPairs[i].y;
        trackers[trkIdx].update(detFrameData[detIdx].box);
    }

    // create and initialise new trackers for unmatched detections
    for (auto umd: unmatchedDetections) {
        KalmanTracker tracker = KalmanTracker(detFrameData[umd]);
        trackers.push_back(tracker);
    }

    // get trackers' output
    frameTrackingResult.clear();
    for (auto it = trackers.begin(); it != trackers.end();) {
//        if (((*it).m_time_since_update < 1) && ((*it).m_hit_streak >= min_hits || frame_count <= min_hits)) {
        if (((*it).m_time_since_update < 1) && ((*it).m_hit_streak >= min_hits)) {
            TrackingBox res;
            res.box = (*it).get_state();
            res.id = (*it).m_id + 1;
            res.className = (*it).className;
            res.distance = (*it).distance;

            frameTrackingResult.push_back(res);
            it++;
        } else
            it++;

        // remove dead tracklet
        if (it != trackers.end() && (*it).m_time_since_update > max_age)
            it = trackers.erase(it);
    }

    return this->frameTrackingResult;
}


double Sort::GetIOU(Rect_<float> bb_test, Rect_<float> bb_gt) {
    float in = (bb_test & bb_gt).area();//intersect
    float un = bb_test.area() + bb_gt.area() - in;//union

    if (un < DBL_EPSILON)//小于最小误差，==0
        return 0;

    return (double) (in / un);
}

