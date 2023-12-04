#ifndef MODULE_HPP
#define MODULE_HPP

#ifndef BASE_HPP
#include "Base.hpp"
#endif

//If you see the method like this std::pair<std::string, bool> Module::Test(RunParameters& runParameters) ->
//This method launches by operator

class Module : public Base
{
private:
    std::condition_variable m_ActivityConditionVariable;

    std::mutex m_ActivityMutex;

protected:
    std::thread runThread_;

    void ActivitySensor();

    virtual void Run() = 0;

public:

    explicit Module(const std::string& nameOfNode);

    virtual void Start() = 0;

    bool IsAlive(const std::chrono::seconds &howMuchToWaitForRespond);

    virtual ~Module();
};

#endif //MODULE_HPP