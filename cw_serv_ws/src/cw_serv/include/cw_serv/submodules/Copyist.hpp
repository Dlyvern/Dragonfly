#ifndef COPYIST_HPP
#define COPYIST_HPP

#ifndef SUBMODULE_HPP
#include "SubModule.hpp"
#endif

#include "boost/filesystem.hpp"
#include "rclcpp/serialization.hpp"
#include "rosbag2_cpp/reader.hpp"
#include "QStorageInfo"
#include "QTextStream"

class Copyist : public SubModule
{
private:
    rosbag2_cpp::Reader m_Reader;
    rclcpp::Serialization<std_msgs::msg::String> m_Serialization;

    std::string m_BagDir{"bags/bags_0.db3"};

    void Run() override;

    std::pair<std::string, bool> CopyFromBagsToFlash(RunParameters &runParameters);


    QString FindFlash();


public:

    void Start() override;

    explicit Copyist(const std::string &nameOfNode, QWidget *parent = nullptr);

    virtual ~Copyist();
};
#endif //COPYIST_HPP
