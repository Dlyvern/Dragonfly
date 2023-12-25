#include "submodules/Copyist.hpp"


Copyist::Copyist(const std::string &nameOfNode, QObject *parent) : QObject(parent), SubModule(nameOfNode)
{
}

void Copyist::Start()
{
    allActions_["Copyist"]["CopyFromBagsToFlash"] = std::bind(&Copyist::CopyFromBagsToFlash, this, std::placeholders::_1);
    Log("Copyist started", INFO_LEVEL_LOG);
}

void Copyist::Run()
{

}

QString Copyist::FindFlash()
{
//TO-DO FIX IT
    std::string lsblkOutput;

    std::ifstream lsblkPipe("lsblk");

    if (lsblkPipe.is_open())
    {
        std::string line;

        while (std::getline(lsblkPipe, line))
        {
            lsblkOutput.append(line);
        }

        lsblkPipe.close();
    }

    std::regex dirRegex("/media/lb/.+");
    std::smatch match;

    if (std::regex_search(lsblkOutput, match, dirRegex))
        return {match.str().c_str()};

    return{};
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

                in << ros_msg.data.c_str() << "\n";
            }
        }

        flash_drive_bag_file.close();
    }

    catch(std::exception& exception)
    {
        return {"something_happened_while_copying_bag_file_to_flash", false};
    }

    m_Reader.close();

    return {"copy_to_flash_completed", true};
}

std::pair<std::string, bool> Copyist::Disable(RunParameters &runParameters)
{
    return {"copyist_disabled", true};
}

Copyist::~Copyist() = default;