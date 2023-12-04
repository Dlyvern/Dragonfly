#include <QApplication>
#include "MainNode.hpp"

//TO-DO:
//Every module has to have publisher(/cw/telemetry/NAME_OF_MODULE) and telemetry module has to have subscribers of all other modules.
// Telemetry data - map
//Every module has to make serialization on its telemetry data and then publish it with publisher
//Telemetry module catch telemetry data and show it
//Logger and Tester should not have publishers for telemetry(Because they have nothing to send and show)

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    rclcpp::init(argc, argv);

    std::shared_ptr<MainNode>main_node = std::make_shared<MainNode>();

    while(rclcpp::ok())
    {
        app.processEvents();
        rclcpp::spin_some(main_node);
    }

    rclcpp::shutdown();

    return 0;
}