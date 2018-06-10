#include "object_detection.h"
#include "mtcnn.h"

static mtcnn mm;

ObjectDetection::ObjectDetection()
{
}

std::vector<cv::Rect> ObjectDetection::detectObject(const cv::Mat& _frame)
{
    std::vector<cv::Rect> boxes;
    mm.detect(_frame, boxes); 
    return boxes;
}
