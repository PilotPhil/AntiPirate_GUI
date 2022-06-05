#ifndef DETECTRES_H
#define DETECTRES_H

#include <QObject>
#include <iostream>
#include <string>

using namespace std;

class DetectRes : public QObject {
    Q_OBJECT
public:
    explicit DetectRes(const int _classId, const string& _className,
        const float _confidence, const float _left,
        const float _top, const float _right, const float _bottom, const float _distance,
        QObject* parent = nullptr);

    DetectRes();
    ~DetectRes();

    DetectRes(const DetectRes& res);

    virtual DetectRes& operator=(const DetectRes& res);

    int ClassID() const { return classId; }
    string ClassName() const { return className; }
    float Confidence() const { return confidence; }
    float Left() const { return left; }
    float Top() const { return top; }
    float Right() const { return right; }
    float Bottom() const { return bottom; }
    float Distance() const { return distance; }
    void SetDistance(float dis) { this->distance = dis; }

    float GetCenterX() const { return (left + right) / 2.0; }
    float GetCenterY() const { return (top + bottom) / 2.0; }

signals:

private:
    int classId;
    string className;
    float confidence;
    float left;
    float top;
    float right;
    float bottom;
    float distance;
};

#endif // DETECTRES_H
