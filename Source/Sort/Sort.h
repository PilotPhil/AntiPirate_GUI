//
// Created by dwb on 2022/2/9.
//

#ifndef SORT_CPP_SORT_H
#define SORT_CPP_SORT_H

#include <iostream>
#include <set>
#include <opencv2/core.hpp>
#include <QObject>

#include "TrackBox.h"
#include "KalmanTracker.h"
#include "Hungarian.h"

using namespace std;
using namespace cv;


class Sort : public QObject {
Q_OBJECT
public:
    Sort(QObject *parent = nullptr);

    ~Sort();

    vector<TrackingBox> process(vector<TrackingBox> detFrameData);

private:
    double GetIOU(Rect_<float> bb_test, Rect_<float> bb_gt);

    double iouThreshold = 0.3;
    int max_age = 1;
    int min_hits = 3;

    vector<KalmanTracker> trackers;

//    vector<TrackingBox> detFrameData;
    vector<Rect_<float>> predictedBoxes;
    vector<vector<double>> iouMatrix;
    vector<int> assignment;
    set<int> unmatchedDetections;
    set<int> unmatchedTrajectories;
    set<int> allItems;
    set<int> matchedItems;
    vector<cv::Point> matchedPairs;
    vector<TrackingBox> frameTrackingResult;
    unsigned int trkNum = 0;
    unsigned int detNum = 0;
    HungarianAlgorithm HungAlgo;
};


#endif //SORT_CPP_SORT_H
