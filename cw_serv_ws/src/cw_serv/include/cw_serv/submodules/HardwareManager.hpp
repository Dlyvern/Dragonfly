#ifndef HARDWARE_MANAGER_HPP
#define HARDWARE_MANAGER_HPP

#include "submodules/SubModule.hpp"

class HardwareManager : public SubModule
{
private:
    void Run() override;
public:
    explicit HardwareManager(std::string name);

    void Start() override;

    ~HardwareManager();
};

#endif //HARDWARE_MANAGER_HPP
