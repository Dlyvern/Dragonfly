#include "submodules/Recorder.hpp"
#include "MainNode.hpp"


Recorder::Recorder(const std::string& nameOfNode) : SubModule(nameOfNode)
{
    m_Writer = std::make_unique<rosbag2_cpp::Writer>();

    for(const auto& topic : m_RecTopics)
    {
        m_Subscriptions.emplace_back(create_subscription<std_msgs::msg::String>(
                topic, 10, std::bind(&Recorder::CallbackFromTopics, this, std::placeholders::_1)));
    }
}

void Recorder::Start()
{
    allActions_["Recorder"]["Enable"] = std::bind(&Recorder::Enable, this, std::placeholders::_1);
    allActions_["Recorder"]["Disable"] = std::bind(&Recorder::Disable, this, std::placeholders::_1);

    try
    {
        m_Writer->open(m_BagDir);
    }

    catch(const std::exception& exception)
    {
        Log("Something went wrong while opening bag directory. Trying to delete old bag directory...", WARN_LEVEL_LOG);

        if (boost::filesystem::exists(m_BagDir))
        {
            try
            {
                boost::filesystem::remove_all(m_BagDir);
            }

            catch (const boost::filesystem::filesystem_error& e)
            {
                Log("Caught exception while deleting old bag directory", ERROR_LEVEL_LOG);
                return;
            }

            Log("Old bag directory successfully deleted", INFO_LEVEL_LOG);
        }
        else
        {
            Log("There is no old bag directory. Maybe error was called cause ros2 is not ok...", ERROR_LEVEL_LOG);
            return;
        }
    }
    Log("Recorder started", INFO_LEVEL_LOG);
}

void Recorder::Run()
{

}

void Recorder::CallbackFromTopics(std::shared_ptr<rclcpp::SerializedMessage> msg)
{
    if(!IsActive()) return;

    rclcpp::Time time_stamp = this->now();

    try
    {
        m_Writer->write(std::move(msg), "/cw/logger", "std_msgs/msg/String", time_stamp);
    }

    catch(const std::exception& exception)
    {
        Log("Something went wrong while write in bag directory", ERROR_LEVEL_LOG);
    }
}

std::pair<std::string, bool> Recorder::Enable(RunParameters &runParameters)
{
    if(IsActive()) return {"recorder_already_enabled", false};

    Log("Start recording to " + m_BagDir, INFO_LEVEL_LOG);

    SetActive(true);

    return {"recorder_is_enabled", true};
}

std::pair<std::string, bool> Recorder::Disable(RunParameters &runParameters)
{
    if(!IsActive()) return {"disabled_already", false};

    SetActive(false);

    return {"recorder_disabled", true};
}

Recorder::~Recorder() = default;