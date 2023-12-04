#include "submodules/SubModule.hpp"

SubModule::SubModule(const std::string& nameOfNode) : Base(nameOfNode)
{

}

void SubModule::SetActive(bool active)
{
    if(m_IsActive == active) return;
    m_IsActive = active;
}

bool SubModule::IsActive() const
{
    return m_IsActive;
}

SubModule::~SubModule() = default;
