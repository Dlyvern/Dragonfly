#include "MainNode.hpp"

MainNode::MainNode() : rclcpp::Node("CableWalker")
{
    m_LogPublisher = this->create_publisher<std_msgs::msg::String>("/cw/log", 100);

    rclcpp::executors::StaticSingleThreadedExecutor::SharedPtr rosExecutor = std::make_shared<rclcpp::executors::StaticSingleThreadedExecutor>();

    m_Modules.emplace_back(std::make_shared<Logger>("logger"));
    m_Modules.emplace_back(std::make_shared<TCPServer>("srv"));
    m_Modules.emplace_back(std::make_shared<Robot>("rb"));

    for(const auto& module : m_Modules)
    {
        module->Start();
        rosExecutor->add_node(module);
    }

    std::thread(std::bind(&rclcpp::executors::StaticSingleThreadedExecutor::spin, rosExecutor)).detach();
    std::thread([this]{Work();}).detach();
}

void MainNode::Work()
{
    while(rclcpp::ok())
    {
        for(auto&module : m_Modules)
        {
            if (!module->IsAlive(std::chrono::seconds(10)))
            {
                Log("Module " + std::string(module->get_name()) + " is not responding, performing force restart");
            }
        }
    }
}

void MainNode::Log(const std::string &message)
{
    auto msg = std::make_shared<std_msgs::msg::String>();

    std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());

    std::stringstream ss;

    ss << std::put_time(std::localtime(&time), "%d-%m-%y %H:%M:%S");

    msg->data = ss.str() + "|[Main]: " + message + std::to_string(0);

    m_LogPublisher->publish(*msg);
}

MainNode::~MainNode() = default;