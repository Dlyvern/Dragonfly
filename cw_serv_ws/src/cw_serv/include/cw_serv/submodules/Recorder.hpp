#ifndef RECORDER_HPP
#define RECORDER_HPP

#ifndef SUBMODULE_HPP
#include "SubModule.hpp"
#endif

#include "boost/filesystem.hpp"
#include <rosbag2_cpp/writer.hpp>
#include <std_msgs/msg/string.hpp>

class Recorder : public SubModule
{
private:
    std::unique_ptr<rosbag2_cpp::Writer> m_Writer{nullptr};
    std::string m_BagDir{"bags"};

    std::vector<rclcpp::Subscription<std_msgs::msg::String>::SharedPtr>m_Subscriptions;

    std::vector<std::string>m_RecTopics
    {
        "/cw/logger",
        "/cw/robot/status"
    };

    std::pair<std::string, bool> Enable(RunParameters& runParameters);

    void Run() override;

    void CallbackFromTopics(std::shared_ptr<rclcpp::SerializedMessage> msg);
public:

    void Start() override;

    std::pair<std::string, bool>Disable(RunParameters& runParameters)override;

    explicit Recorder(const std::string& nameOfNode);

    virtual ~Recorder();
};

#endif //RECORDER_HPP
