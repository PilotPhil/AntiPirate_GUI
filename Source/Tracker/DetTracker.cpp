#include "DetTracker.h"

DetTracker::DetTracker(YOLO* yolo, QObject* parent)
    : _yolo(yolo)
    , QObject { parent }
{
}

DetTracker::~DetTracker() { }

void DetTracker::SetMediaPath(const String& pth)
{
    this->_media_path = pth;
}