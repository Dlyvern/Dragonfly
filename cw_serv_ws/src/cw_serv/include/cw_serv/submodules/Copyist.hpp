#ifndef COPYIST_HPP
#define COPYIST_HPP

#ifndef SUBMODULE_HPP
#include "SubModule.hpp"
#endif

#include "rclcpp/serialization.hpp"
#include "rosbag2_cpp/reader.hpp"
#include "QStorageInfo"
#include "QTextStream"
#include "regex"
#include <fstream>

class Copyist : public QObject, public SubModule
{
    Q_OBJECT
private:
    rosbag2_cpp::Reader m_Reader;
    rclcpp::Serialization<std_msgs::msg::String> m_Serialization;

    std::string m_BagDir{"bags/bags_0.db3"};

    void Run() override;

    std::pair<std::string, bool> CopyFromBagsToFlash(RunParameters &runParameters);

    QString FindFlash();

public:
    void Start() override;

    explicit Copyist(const std::string &nameOfNode, QObject *parent = nullptr);

    std::pair<std::string, bool>Disable(RunParameters& runParameters) override;

    virtual ~Copyist();
};
#endif //COPYIST_HPP
