#ifndef UTIL_H
#define UTIL_H

#include "NetConfig.h"
#include "yolo.h"

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

#include <QLabel>
using namespace cv;

Mat DetectImg(YOLO& yolo_model,string& img_src,bool is_show_opencv_window=false);

void DetectVideo(YOLO& yolo_model,string& video_src);

void ShowImg2Label(QLabel& label,Mat& mat);


#endif
