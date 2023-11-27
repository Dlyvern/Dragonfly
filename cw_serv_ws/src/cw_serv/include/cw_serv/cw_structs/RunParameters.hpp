#ifndef RUN_PARAMETERS_HPP
#define RUN_PARAMETERS_HPP

#include "string"
#include "vector"

struct RunParameters
{
public:
    std::vector<std::string>arguments;
    int progress{0};
    time_t timeLimit{15};

    RunParameters();

    ~RunParameters();
};


#endif //RUN_PARAMETERS_HPP
