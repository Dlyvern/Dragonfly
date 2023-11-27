#include "submodules/SubModule.hpp"

#include <utility>

SubModule::SubModule(std::string name) : m_Name{std::move(name)}
{

}

const std::string &SubModule::GetName() const
{
    return m_Name;
}

SubModule::~SubModule() = default;
