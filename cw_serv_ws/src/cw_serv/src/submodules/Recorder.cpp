#include "submodules/Recorder.hpp"

#include <utility>

Recorder::Recorder(const std::string& nameOfNode, QWidget *parent) : SubModule(nameOfNode, parent)
{
    m_Writer = std::make_unique<rosbag2_cpp::Writer>();
    allActions_["Recorder"]["Enable"] = std::bind(&Recorder::Enable, this, std::placeholders::_1);
}

void Recorder::Start()
{

}

void Recorder::Run()
{

}

void Recorder::CallbackFromTopics(std::shared_ptr<rclcpp::SerializedMessage> msg)
{
    rclcpp::Time time_stamp = this->now();

    m_Writer->write(std::move(msg), "/cw/logger", "std_msgs/msg/String", time_stamp);
}

std::pair<std::string, bool> Recorder::Enable(RunParameters &runParameters)
{
    if(m_Active) return {"recorder_already_enabled", false};

    m_Active = true;

    for(const auto& topic : m_RecTopics)
    {
        m_Subscriptions.emplace_back(create_subscription<std_msgs::msg::String>(
                topic, 10, std::bind(&Recorder::CallbackFromTopics, this, std::placeholders::_1)));
    }

    if (boost::filesystem::exists(m_BagDir))
    {
        try
        {
            boost::filesystem::remove_all(m_BagDir);
        }
        catch (const boost::filesystem::filesystem_error& e)
        {
            return {"something_went_wrong_while_deleting_old_bag_directory", false};
        }
    }

    try
    {
        m_Writer->open(m_BagDir);
    }

    catch(const std::exception& exception)
    {
        return {"something_went_wrong_while_opening_bag_directory", false};
    }

    Log("Start recording to " + m_BagDir, INFO_LEVEL_LOG);

    return {"recorder_is_enabled", true};
}

Recorder::~Recorder() = default;