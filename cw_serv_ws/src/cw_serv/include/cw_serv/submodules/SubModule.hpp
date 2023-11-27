#ifndef SUBMODULE_HPP
#define SUBMODULE_HPP

#include "string"

class SubModule
{
private:
    std::string m_Name{"NOT_SET"};
protected:
    virtual void Run() = 0;
public:
    explicit SubModule(std::string  name);

    virtual void Start() = 0;

    [[nodiscard]]const std::string& GetName() const;

    ~SubModule();
};
#endif //SUBMODULE_HPP
