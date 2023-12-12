#include "devices/RtspCamera.hpp"

RtcpCamera::RtcpCamera(const std::string &nodeName) : Device(nodeName)
{
//    username = admin
//    password = admin
//    stream = ch01/0
//    hostname = 192.168.31.232
//    <arg name="camera_name" default="rtsp_camera" />
//    <arg name="camera_frame" default="rtsp_camera_link" />
//    <arg name="image_raw_topic" default="image_raw" />
//    <arg name="camera_info_topic" default="camera_info" />
//    <param name="rtsp_resource" value="rtsp://$(arg username):$(arg password)@$(arg hostname):$(arg port)/$(arg stream)" />
//    <param name="camera_name" value="$(arg camera_name)" />
//    <param name="camera_frame" value="$(arg camera_frame)" />
//    <param name="image_raw_topic" value="$(arg image_raw_topic)" />
//    <param name="camera_info_topic" value="$(arg camera_info_topic)" />

    this->declare_parameter("rtsp_resource", "rtsp://admin:admin@192.168.31.232:554/ch01/0");

}

void RtcpCamera::Start()
{

}

void RtcpCamera::Run()
{

}



RtcpCamera::~RtcpCamera() = default;
