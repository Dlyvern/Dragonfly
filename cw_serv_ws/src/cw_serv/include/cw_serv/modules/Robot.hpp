#ifndef ROBOT_HPP
#define ROBOT_HPP


#ifndef MODULE_HPP
#include "Module.hpp"
#endif

#include "QTimer"
#include "QDebug"

#ifndef HARDWARE_MANAGER_HPP
#include "submodules/HardwareManager.hpp"
#endif

#ifndef RECORDER_HPP
#include "submodules/Recorder.hpp"
#endif


#ifndef COPYIST_HPP
#include "submodules/Copyist.hpp"
#endif

class Robot : public Module
{
    Q_OBJECT
private:

    QTimer* m_SubmodulesSpinTimer;

    std::vector<std::shared_ptr<SubModule>>m_Submodules;

    bool m_Active{false};

    QTimer *m_RunTimer{nullptr};

    std::pair<std::string, bool> Enable(RunParameters& runParameters);

    std::pair<std::string, bool> Disable(RunParameters& runParameters);

    void LaunchGoose();

    void InitSubmodules();

    std::pair<std::string, bool> DoDiagnostic(RunParameters& runParameters);

    std::pair<std::string, bool> MoveToTower(RunParameters& runParameters);

    std::pair<std::string, bool> MoveToPrevTower(RunParameters& runParameters);

    std::pair<std::string, bool> MoveToFurthestTower(RunParameters& runParameters);


    std::pair<std::string, bool> LongTest(RunParameters& runParameters);

private slots:
    void Run() override;

public:
    explicit Robot(const std::string& nameOfNode, QWidget *parent = nullptr);

    void Start() override;

    virtual ~Robot();
};
#endif //ROBOT_HPP