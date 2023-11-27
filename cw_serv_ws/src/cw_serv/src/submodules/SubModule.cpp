#include "submodules/SubModule.hpp"

#include <utility>

SubModule::SubModule(const std::string& nameOfNode, QWidget *parent) : Base(nameOfNode, parent)
{

}

SubModule::~SubModule() = default;
