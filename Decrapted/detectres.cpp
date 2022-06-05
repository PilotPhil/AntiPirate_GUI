#include "detectres.h"

DetectRes::DetectRes(const int _classId, const string &_className,
                     const float _confidence, const float _left,
                     const float _top, const float _right,
                     const float _bottom, const float _distance, QObject *parent)
    : classId(_classId), className(_className), confidence(_confidence),
      left(_left), top(_top), right(_right),
      bottom(_bottom),distance(_distance), QObject{parent} {}

DetectRes::DetectRes()
{

}

DetectRes::~DetectRes()
{

}

DetectRes::DetectRes(const DetectRes &res)
{
    this->classId=res.classId;
    this->className=res.className;
    this->confidence=res.confidence;
    this->left=res.left;
    this->top=res.top;
    this->right=res.right;
    this->bottom=res.bottom;
    this->distance=res.distance;
}

DetectRes &DetectRes::operator=(const DetectRes &res)
{
    this->classId=res.classId;
    this->className=res.className;
    this->confidence=res.confidence;
    this->left=res.left;
    this->top=res.top;
    this->right=res.right;
    this->bottom=res.bottom;
    this->distance=res.distance;

    return *this;
}
