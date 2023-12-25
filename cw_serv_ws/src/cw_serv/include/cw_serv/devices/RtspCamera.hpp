#ifndef RTSP_CAMERA_HPP
#define RTSP_CAMERA_HPP
#include "opencv2/opencv.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/camera_info.hpp"
#include "sensor_msgs/msg/compressed_image.hpp"
#include "Device.hpp"

class RtcpCamera : public Device
{
private:
    void Run() override;
    cv::VideoCapture m_VideoCapture;
    std::thread m_WorkThread;
public:
    explicit RtcpCamera(const std::string& nodeName);

    std::pair<std::string, bool> Enable(RunParameters& runParameters);


    void Start() override;
    virtual ~RtcpCamera();
};

#endif //RTSP_CAMERA_HPP
