#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "Base.hpp"

class Device : public Base
{
private:
    virtual void Run() = 0;
public:
    explicit Device(const std::string& nodeName);
    virtual void Start() = 0;
    virtual ~Device();
};


#endif //DEVICE_HPP
