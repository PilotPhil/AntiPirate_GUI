#include <fstream>
#include <cstring>
#include <string.h>
#include <sstream>
#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/dnn/layer.details.hpp>

using namespace cv;
using namespace dnn;
using namespace std;

struct Net_config				// ��������
{
    float confThreshold;		// ���Ŷ�����
    float nmsThreshold;			// NMS����
    int inpWidth;				// ģ������ͼ����
    int inpHeight;				// ģ�����ͼ��߶�
    string classesFile;			// ���������Ƶ��ļ� coco.name
    string modelConfiguration;	// ģ���ļ�  .cfg
    string modelWeights;		// ģ��Ȩ���ļ�
    string netname;				// ��������
};


class YOLO {
public:
    YOLO(Net_config config);				// ���캯��
    void detect(Mat& frame);				// ���м��
    void setcapSize(int width, int height);		// ��ȡ����ͷ�ķֱ���
private:
    float confThreshold;			// ���Ŷ�����
    float nmsThreshold;				// nms����
    int inpWidth;					// ģ������ͼ����
    int inpHeight;					// ģ������ͼ��߶�
    int capWidth;					// �������ͼ��Ŀ��
    int capHeight;					// �������ͼ��ĸ߶�
    float scaleHeight;				// ģ������ͼ���������ͼ��ĸ߶���������
    float scaleWidth;				// ģ������ͼ���������ͼ��Ŀ����������
    char netname[20];				// ��������
    vector<string> classes;			// �����������
    Net net;						// dnn::net����
    void postprocess(Mat& frame, const vector<Mat>& outs);			// ������Ҫ��ʹ��nmsɸѡĿ��
    void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame);// ����Ŀ��ļ�����Լ����ŶȵȲ���
};


class ExpLayer : public cv::dnn::Layer {       // �Զ��������Exp���ο�https://github.com/berak/opencv_smallfry/blob/605f5fdb4b55d8e5fe7e4c859cb0784d1007ffdd/demo/cpp/pnet.cpp
public:
    ExpLayer(const cv::dnn::LayerParams &params) : Layer(params) {
    }

    static cv::Ptr<cv::dnn::Layer> create(cv::dnn::LayerParams& params) {
        return cv::Ptr<cv::dnn::Layer>(new ExpLayer(params));
    }

    virtual bool getMemoryShapes(const std::vector<std::vector<int> > &inputs,
        const int requiredOutputs,
        std::vector<std::vector<int> > &outputs,
        std::vector<std::vector<int> > &internals) const CV_OVERRIDE {
        CV_UNUSED(requiredOutputs); CV_UNUSED(internals);
        std::vector<int> outShape(4);
        outShape[0] = inputs[0][0];  // batch size
        outShape[1] = inputs[0][1];  // number of channels
        outShape[2] = inputs[0][2];
        outShape[3] = inputs[0][3];
        outputs.assign(1, outShape);
        return false;
    }

    virtual void forward(cv::InputArrayOfArrays inputs_arr,
        cv::OutputArrayOfArrays outputs_arr,
        cv::OutputArrayOfArrays internals_arr) CV_OVERRIDE {
        std::vector<cv::Mat> inputs, outputs;
        inputs_arr.getMatVector(inputs);
        outputs_arr.getMatVector(outputs);

        cv::Mat& inp = inputs[0];
        cv::Mat& out = outputs[0];

        exp(inp, out);			// �ؼ���һ�����
    }
};
