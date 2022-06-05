//
// Created by dwb on 2022/2/10.
//

#ifndef ANTIPIRATEGUI_PERFINFO_H
#define ANTIPIRATEGUI_PERFINFO_H

#include <iostream>
#include <string>

using namespace std;

typedef struct PerfInfo {
    float inference_time;
    float process_time;
    float fps;
} PerfInfo;

#endif //ANTIPIRATEGUI_PERFINFO_H
