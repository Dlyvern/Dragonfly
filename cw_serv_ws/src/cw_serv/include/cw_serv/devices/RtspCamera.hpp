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
public:
    explicit RtcpCamera(const std::string& nodeName);

    void Start() override;
    virtual ~RtcpCamera();
};

#endif //RTSP_CAMERA_HPP
