#ifndef MAIN_NODE_HPP
#define MAIN_NODE_HPP

#include <rclcpp/node.hpp>

#ifndef TCP_SERVER_HPP
#include "modules/TCPServer.hpp"
#endif

#include "modules/Logger.hpp"

#include "modules/Robot.hpp"

class MainNode : public rclcpp::Node
{
private:
    static std::shared_ptr<MainNode>m_Myself;
    std::vector<std::shared_ptr<Module>>m_Modules;
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>m_LogPublisher{nullptr};
public:
    MainNode();

    void Work();

    void Log(const std::string& message);

    virtual ~MainNode();
};

#endif //MAIN_NODE_HPP