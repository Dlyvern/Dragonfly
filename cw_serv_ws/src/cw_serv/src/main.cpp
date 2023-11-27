#include <QApplication>
#include <QSettings>
#include "modules/TCPServer.hpp"
#include "modules/Logger.hpp"
#include "modules/Robot.hpp"

//TO-DO:
//Every module has to have publisher(/cw/telemetry/NAME_OF_MODULE) and telemetry module has to have subscribers of all other modules.
// Telemetry data - map
//Every module has to make serialization on its telemetry data and then publish it with publisher
//Telemetry module catch telemetry data and show it
//Logger and Tester should not have publishers for telemetry(Because they have nothing to send and show)
//Make launch files

void CheckModules( const std::map<std::string, std::shared_ptr<Module>>&modules)
{
    while(rclcpp::ok())
    {
        for(auto&module : modules)
        {
            if(!module.second->IsAlive(std::chrono::seconds(10)))
            {
                std::string s = "Module " + module.first + " is not responding, performing force restart";
                qDebug() << QString{s.c_str()};
                //Log("Module " + module.first + " is not responding, performing force restart");
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

void Log(const std::string &message)
{
    auto msg = std::make_shared<std_msgs::msg::String>();

    std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());

    std::stringstream ss;

    ss << std::put_time(std::localtime(&time), "%d-%m-%y %H:%M:%S");

    msg->data = ss.str() + "|[Main]: " + message + std::to_string(0);

  //  m_LogPublisher->publish(*msg);
}

void SpinNodes(rclcpp::executors::MultiThreadedExecutor&multi_executor )
{
    while(rclcpp::ok())
    {
        multi_executor.spin_some();
    }
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    rclcpp::init(argc, argv);

//    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>m_LogPublisher{nullptr};

    rclcpp::executors::MultiThreadedExecutor multi_executor;

    std::thread check_thread;
    std::thread spin_thread;

    //m_LogPublisher = m_ParametersNode->create_publisher<std_msgs::msg::String>("/cw/log", 100);

    std::map<std::string, std::shared_ptr<Module>>modules =
    {
            {"Server", std::make_shared<TCPServer>("srv")},
            {"Logger", std::make_shared<Logger>("logger")},
            {"Robot", std::make_shared<Robot>("rb")},
    };


    for(const auto&module : modules)
    {
        module.second->Start();
        multi_executor.add_node(module.second);
    }

    check_thread = std::thread([&]{CheckModules(modules);});
    check_thread.detach();

    spin_thread = std::thread([&]{SpinNodes(multi_executor);});
    spin_thread.detach();

    int return_value = app.exec();

    rclcpp::shutdown();

    return return_value;
}