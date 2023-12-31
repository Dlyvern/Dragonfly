#include "modules/Robot.hpp"

Robot::Robot(const std::string &nameOfNode, QObject *parent) : QObject(parent), Module(nameOfNode)
{
    m_RunTimer = new QTimer;
    SetRunInterval(std::chrono::seconds(1));
    m_RunTimer->setInterval(GetRunInterval());
    connect(m_RunTimer, &QTimer::timeout, this, &Robot::Run);

    m_SubmodulesSpinTimer = new QTimer;
    m_SubmodulesSpinTimer->setInterval(1);

    connect(m_SubmodulesSpinTimer, &QTimer::timeout, [this]
    {
        for(const auto&submodule : m_Submodules)
        {
            spin_some(submodule);
        }
    });

    m_Submodules.emplace_back(std::make_shared<HardwareManager>("HardwareManager"));
    m_Submodules.emplace_back(std::make_shared<Recorder>("Recorder"));
    m_Submodules.emplace_back(std::make_shared<Copyist>("Copyist"));

    allActions_["Robot"]["Enable"] = std::bind(&Robot::Enable, this, std::placeholders::_1);
    allActions_["Robot"]["DoDiagnostic"] = std::bind(&Robot::DoDiagnostic, this, std::placeholders::_1);
    allActions_["Robot"]["LongTest"] = std::bind(&Robot::LongTest, this, std::placeholders::_1);
    allActions_["Robot"]["Disable"] = std::bind(&Robot::Disable, this, std::placeholders::_1);
}

void Robot::Start()
{
    m_RunTimer->start();
    m_SubmodulesSpinTimer->start();
}

void Robot::InitSubmodules()
{
    for(const auto&sub_module : m_Submodules)
        sub_module->Start();
}

void Robot::Run()
{
    ActivitySensor();
}

std::pair<std::string, bool> Robot::Enable(RunParameters& runParameters)
{
    if(m_Active)
    {
        return {"robot_already_enabled", false};
    }

    LaunchGoose();

    InitSubmodules();

    auto rtsp_camera = new RtcpCamera{"rtsp_camera"};

    rtsp_camera->Start();

    m_Active = true;

    return {"robot_enabled", true};
}

std::pair<std::string, bool>Robot::Disable(RunParameters& runParameters)
{
    if(!m_Active) return {"robot_already_disabled", false};

    RunParameters rp;

    for(auto& submodule : m_Submodules)
        submodule->Disable(rp);

    m_Active = false;

    return {"robot_disabled", true};
}


void Robot::LaunchGoose()
{
    QByteArray gs = "\n\n\xd0\x97\xd0\x90\xd0\x9f\xd0\xa3\xd0\xa1\xd0\x9a\xd0\x90\xd0\x95\xd0\x9c\n\xe2\x96\x91\xd0\x93\xd0\xa3\xd0\xa1\xd0\xAF\xe2\x96\x91\xe2"
                    "\x96\x84\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x84\xe2\x96\x91\xd0\x9a\xd0\x90\xd0\x9d\xd0\x90\xd0\xa2\xd0\x9e\xd0\xa5\xd0\x9e\xd0"
                    "\x94\xd0\xa6\xd0\x90\xe2\x96\x91\xe2\x96\x91\n\xe2\x96\x84\xe2\x96\x88\xe2\x96\x88\xe2\x96\x88\xe2\x96\x80\xe2\x96\x91\xe2\x97\x90\xe2\x96"
                    "\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x8c\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\n\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x8c\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x90\xe2\x96\x91\xe2\x96"
                    "\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\n\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x90\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x90\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96"
                    "\x91\n\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x8c\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x90"
                    "\xe2\x96\x84\xe2\x96\x84\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\n\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2"
                    "\x96\x8c\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x84\xe2\x96\x80\xe2\x96\x92\xe2\x96\x92\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80"
                    "\xe2\x96\x80\xe2\x96\x84\n\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x90\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x90\xe2"
                    "\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x80\xe2\x96\x80\xe2\x96\x84\n\xe2\x96"
                    "\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x90\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x90\xe2\x96\x84\xe2\x96\x92\xe2\x96\x92"
                    "\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x80\xe2\x96\x84\n\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x80\xe2\x96\x84\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x80\xe2\x96\x84"
                    "\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x92\xe2\x96\x80"
                    "\xe2\x96\x84\n\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x80\xe2\x96\x84\xe2\x96\x84\xe2\x96"
                    "\x84\xe2\x96\x84\xe2\x96\x84\xe2\x96\x88\xe2\x96\x84\xe2\x96\x84\xe2\x96\x84\xe2\x96\x84\xe2\x96\x84\xe2\x96\x84\xe2\x96\x84\xe2\x96\x84"
                    "\xe2\x96\x84\xe2\x96\x84\xe2\x96\x84\xe2\x96\x80\xe2\x96\x84\n\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x8c\xe2\x96\x8c\xe2\x96\x8c\xe2\x96\x8c\xe2\x96\x91\xe2\x96\x91\xe2\x96"
                    "\x91\xe2\x96\x91\xe2\x96\x91\n\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91"
                    "\xe2\x96\x91\xe2\x96\x91\xe2\x96\x8c\xe2\x96\x8c\xe2\x96\x91\xe2\x96\x8c\xe2\x96\x8c\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2"
                    "\x96\x91\n\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x84\xe2\x96"
                    "\x84\xe2\x96\x8c\xe2\x96\x8c\xe2\x96\x84\xe2\x96\x8c\xe2\x96\x8c\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\xe2\x96\x91\n\xe2\x96\x80"
                    "\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2\x96\x80\xe2"
                    "\x96\x80";

    QString decoded = QString::fromUtf8(gs);
    Log(decoded.toStdString(), INFO_LEVEL_LOG);
}

std::pair<std::string, bool> Robot::DoDiagnostic(RunParameters& runParameters)
{
    if(!m_Active) return {"robot_is_not_enabled", false};

    std::string result{" "};

    auto steps =
    {
        std::bind(&Robot::MoveToFurthestTower, this, std::placeholders::_1),
        std::bind(&Robot::MoveToPrevTower, this, std::placeholders::_1)
    };

    int index_of_step = 1;

    for(auto&step : steps)
    {
        auto result_of_step = step(runParameters);
        result += "Step " + std::to_string(index_of_step) + " executed with result: " + result_of_step.first + " \n";
        ++index_of_step;
    }

    return {result, true};
}

std::pair<std::string, bool> Robot::MoveToTower(RunParameters& runParameters)
{
    return {"no_tower", false};
}

std::pair<std::string, bool> Robot::MoveToPrevTower(RunParameters& runParameters)
{
    return MoveToTower(runParameters);
}

std::pair<std::string, bool>Robot::MoveToFurthestTower(RunParameters& runParameters)
{
    return MoveToTower(runParameters);
}

std::pair<std::string, bool> Robot::LongTest(RunParameters &runParameters)
{
    rclcpp::Rate rate{0.01};

    for(int i = 0; i < 10; ++i)
        rate.sleep();

    return {"long_test_succeeded", true};
}

Robot::~Robot() = default;