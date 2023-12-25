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

    this->declare_parameter("rtsp_resource", "rtsp://admin:admin@192.168.31.191:554/ch01/0");
}

void RtcpCamera::Start()
{
    allActions_["RtspCamera"]["Enable"] = std::bind(&RtcpCamera::Enable, this, std::placeholders::_1);

    Log("Rtsp camera started", INFO_LEVEL_LOG);
}

void RtcpCamera::Run()
{
    while(IsRunning())
    {
        if(m_VideoCapture.isOpened())
        {
            cv::namedWindow("Test");
            cv::Mat frame;

            while(IsRunning())
            {
                m_VideoCapture.read(frame);

                cv::imshow("Test", frame);
            }
        }
    }
}

std::pair<std::string, bool> RtcpCamera::Enable(RunParameters &runParameters)
{
//    cap.open(this->GetParameter("rtsp_resource").as_string());
    m_VideoCapture.open("rtsp://admin:admin@192.168.31.191:554/ch01/0");

    if(!m_VideoCapture.isOpened())
        return{"could not open rtsp stream", false};

    SetRunning(true);

    m_WorkThread = std::thread([this]{Run();});

    m_WorkThread.detach();

    return{"rtsp stream opened", false};
}

RtcpCamera::~RtcpCamera() = default;
