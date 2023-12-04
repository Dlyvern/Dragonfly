#ifndef SUBMODULE_HPP
#define SUBMODULE_HPP

#ifndef BASE_HPP
#include "Base.hpp"
#endif

class SubModule : public Base
{
private:
    bool m_IsActive{false};
protected:
    virtual void Run() = 0;

    void SetActive(bool active);

    [[nodiscard]]bool IsActive() const;
public:
    explicit SubModule(const std::string& nameOfNode);

    virtual std::pair<std::string, bool>Disable(RunParameters& runParameters) = 0;

    virtual void Start() = 0;

    virtual ~SubModule();
};
#endif //SUBMODULE_HPP
