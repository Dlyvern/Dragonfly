#include "submodules/HardwareManager.hpp"

HardwareManager::HardwareManager(const std::string& nameOfNode) : SubModule(nameOfNode)
{

}

void HardwareManager::Start()
{

}

void HardwareManager::Run()
{

}

std::pair<std::string, bool> HardwareManager::Disable(RunParameters &runParameters)
{
    return {"hardware_manager_disabled", true};
}

HardwareManager::~HardwareManager() = default;