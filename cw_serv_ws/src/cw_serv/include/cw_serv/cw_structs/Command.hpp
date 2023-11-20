#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <memory>
#include <vector>

class Command
{
private:
    std::vector<std::string> m_Target;
    std::string m_Operation;
    std::vector<std::string>m_Arguments;
    int32_t m_TimeLimit{0};
public:

    static Command* FromCommandString(const std::string& cmdStr);

    [[nodiscard]]const std::vector<std::string>& GetTarget() const;

    [[nodiscard]]const std::string& GetOperation() const;

    [[nodiscard]]const std::vector<std::string>& GetArguments() const;

    [[nodiscard]]const int32_t & GetTimeLimit() const;
};

#endif //COMMAND_HPP