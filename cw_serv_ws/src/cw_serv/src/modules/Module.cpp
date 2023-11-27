#include "modules/Module.hpp"

Module::Module(const std::string &nameOfNode, QWidget *parent) : Base(nameOfNode, parent)
{

}


bool Module::IsAlive(const std::chrono::seconds &howMuchToWaitForRespond)
{
    std::unique_lock<std::mutex>unique_lock(m_ActivityMutex);
    return m_ActivityConditionVariable.wait_for(unique_lock, howMuchToWaitForRespond) == std::cv_status::no_timeout;
}

void Module::ActivitySensor()
{
    std::unique_lock<std::mutex>unique_lock(m_ActivityMutex);
    m_ActivityConditionVariable.notify_all();
}

Module::~Module() = default;