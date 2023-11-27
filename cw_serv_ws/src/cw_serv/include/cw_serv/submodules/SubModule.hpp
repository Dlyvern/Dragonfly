#ifndef SUBMODULE_HPP
#define SUBMODULE_HPP

#include "string"

#ifndef BASE_HPP
#include "Base.hpp"
#endif

class SubModule : public Base
{
protected:
    virtual void Run() = 0;
public:
    explicit SubModule(const std::string& nameOfNode, QWidget *parent = nullptr);

    virtual void Start() = 0;

    virtual ~SubModule();
};
#endif //SUBMODULE_HPP
