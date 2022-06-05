#ifndef IMGDETECTOR_H
#define IMGDETECTOR_H

#include <QObject>

#include "DetTracker.h"

class ImgDetector : public Detector {
 public:
  explicit ImgDetector(YOLO* yolo, QObject* parent = nullptr);

  virtual void Start();
  virtual void Pause();
  virtual void Stop();
  virtual void Process();
};

#endif  // IMGDETECTOR_H
