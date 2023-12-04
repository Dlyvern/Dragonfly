#ifndef HARDWARE_MANAGER_HPP
#define HARDWARE_MANAGER_HPP

#include "submodules/SubModule.hpp"

class HardwareManager : public SubModule
{
private:
    void Run() override;
public:
    explicit HardwareManager(const std::string& nameOfNode);

    void Start() override;

    std::pair<std::string, bool> Disable(RunParameters &runParameters) override;

    virtual ~HardwareManager();
};

#endif //HARDWARE_MANAGER_HPP
