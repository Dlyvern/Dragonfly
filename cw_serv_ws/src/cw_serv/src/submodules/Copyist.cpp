#include <fstream>
#include "submodules/Copyist.hpp"

Copyist::Copyist(const std::string &nameOfNode, QWidget *parent) : SubModule(nameOfNode, parent)
{
    allActions_["Copyist"]["CopyFromBagsToFlash"] = std::bind(&Copyist::CopyFromBagsToFlash, this, std::placeholders::_1);
}

void Copyist::Start()
{

}

void Copyist::Run()
{

}

QString Copyist::FindFlash()
{
    QList<QStorageInfo> storageDevices = QStorageInfo::mountedVolumes();

    for (const auto &device : storageDevices)
    {
        if (device.isReadOnly() && device.bytesTotal() > 0)
            return device.rootPath();
    }

    return {};
}

std::pair<std::string, bool> Copyist::CopyFromBagsToFlash(RunParameters &runParameters)
{
    try
    {
        m_Reader.open(m_BagDir);
    }

    catch(std::exception& exception)
    {
        return {"something_happened_while_opening_bag_file", false};
    }

    QString flash_path = FindFlash();

    if(flash_path.isEmpty()) return {"not_a_single_flash_drive_was_found", false};

    Log("Copying to " + flash_path.toStdString(), INFO_LEVEL_LOG);

    try
    {
        QFile flash_drive_bag_file(flash_path + "/bag.txt");

        if (flash_drive_bag_file.open(QIODevice::WriteOnly))
        {
            QTextStream in(&flash_drive_bag_file);

            while (m_Reader.has_next())
            {
                rosbag2_storage::SerializedBagMessageSharedPtr msg = m_Reader.read_next();

                rclcpp::SerializedMessage serialized_msg(*msg->serialized_data);

                std_msgs::msg::String ros_msg;

                m_Serialization.deserialize_message(&serialized_msg, &ros_msg);

                in << ros_msg.data.c_str();
            }
        }

        flash_drive_bag_file.close();
    }

    catch(std::exception& exception)
    {
        return {"something_happened_while_copying_bag_file_to_flash", false};
    }

    return {"copy_to_flash_completed", true};
}

Copyist::~Copyist() = default;