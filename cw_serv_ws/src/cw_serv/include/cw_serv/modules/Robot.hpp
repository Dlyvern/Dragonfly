#ifndef ROBOT_HPP
#define ROBOT_HPP


#ifndef MODULE_HPP
#include "Module.hpp"
#endif

#include "QTimer"
#include "QDebug"

#include "submodules/HardwareManager.hpp"

class Robot : public Module
{
    Q_OBJECT
private:

    std::vector<SubModule*>m_Submodules;

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

private slots:
    void Run() override;

public:
    explicit Robot(const std::string& nameOfNode, QWidget *parent = nullptr);

    void Start() override;

    virtual ~Robot();
};
#endif //ROBOT_HPP
