#ifndef VIDEODETECTOR_H
#define VIDEODETECTOR_H

#include "DetTracker.h"
#include <QObject>
#include <QThread>

class VideoDetTracker : public DetTracker
{
public:
    explicit VideoDetTracker(YOLO* yolo, QObject *parent = nullptr);

    virtual void Start();
    virtual void Pause();
    virtual void Stop();
    virtual void Process();
};

#endif // VIDEODETECTOR_H
