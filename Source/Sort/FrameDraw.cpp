//
// Created by dwb on 2022/2/10.
//

#include <opencv2/imgproc.hpp>
#include "FrameDraw.h"

void FrameDraw::DrawFireBox(const TrackingBox &tb, const cv::Mat &frame) {
//1.draw cross
    //cross changdu
    //float crs_len = 0.2 * tb.box.width;//20% of the width or heigth
    float crs_len = 20;//20pixel
    float ct_x = tb.box.x + tb.box.width / 2;
    float ct_y = tb.box.y + tb.box.height / 2;
    line(frame, cv::Point(ct_x - crs_len / 2, ct_y), cv::Point(ct_x + crs_len / 2, ct_y), CV_RGB(255, 0, 0), 1.5);
    line(frame, cv::Point(ct_x, ct_y - crs_len / 2), cv::Point(ct_x, ct_y + crs_len / 2), CV_RGB(255, 0, 0), 1.5);

    //2.draw border
    //kuang changdu
    float border_len = 0.15 * tb.box.width;//20% of width
//    float border_len = 40;//40pixel
    auto pt1 = cv::Point(tb.box.x, tb.box.y);
    auto pt1_d_1 = cv::Point(tb.box.x + border_len, tb.box.y);
    auto pt1_d_2 = cv::Point(tb.box.x, tb.box.y + border_len);

    auto pt2 = cv::Point(tb.box.x + tb.box.width, tb.box.y);
    auto pt2_d_1 = cv::Point(tb.box.x + tb.box.width - border_len, tb.box.y);
    auto pt2_d_2 = cv::Point(tb.box.x + tb.box.width, tb.box.y + border_len);

    auto pt3 = cv::Point(tb.box.x, tb.box.y + tb.box.height);
    auto pt3_d_1 = cv::Point(tb.box.x + border_len, tb.box.y + tb.box.height);
    auto pt3_d_2 = cv::Point(tb.box.x, tb.box.y + tb.box.height - border_len);

    auto pt4 = cv::Point(tb.box.x + tb.box.width, tb.box.y + tb.box.height);
    auto pt4_d_1 = cv::Point(tb.box.x + tb.box.width - border_len, tb.box.y + tb.box.height);
    auto pt4_d_2 = cv::Point(tb.box.x + tb.box.width, tb.box.y + tb.box.height - border_len);

    auto rgb_1 = CV_RGB(200, 200, 200);
    line(frame, pt1, pt1_d_1, rgb_1, 1.5);
    line(frame, pt1, pt1_d_2, rgb_1, 1.5);
    line(frame, pt2, pt2_d_1, rgb_1, 1.5);
    line(frame, pt2, pt2_d_2, rgb_1, 1.5);
    line(frame, pt3, pt3_d_1, rgb_1, 1.5);
    line(frame, pt3, pt3_d_2, rgb_1, 1.5);
    line(frame, pt4, pt4_d_1, rgb_1, 1.5);
    line(frame, pt4, pt4_d_2, rgb_1, 1.5);


}

void FrameDraw::DrawDetectInfo(const TrackingBox &tb, const cv::Mat &frame, bool showDistance) {
    auto text_color = CV_RGB(255, 0, 0);

    string text = to_string(tb.id) + "-" + tb.className ;

    if(showDistance== true)
    {
        text+=+ "-" + format("%.2fm", tb.distance * 0.001);
    }

    putText(frame, text,
            Point(tb.box.x + 10, tb.box.y + tb.box.height - 10),
            FONT_HERSHEY_SIMPLEX, 0.5,
            text_color, 1);
}
