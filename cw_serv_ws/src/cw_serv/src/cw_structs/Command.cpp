#include "cw_structs/Command.hpp"

//"cmd.target1.target2.operation|arg1,arg2"
Command* Command::FromCommandString(const std::string &cmdStr)
{
    //Example of command that passes in this function: cmd1 = Cmd.from_cmdstr('robot.test_basic|24')
    Command*command = new Command();

    size_t next_target_position = cmdStr.find('.', 0);

    std::vector<std::string>targets;

    size_t prev_target_position = -1;

    while(next_target_position != std::string::npos)
    {
        targets.emplace_back(cmdStr.substr(prev_target_position + 1, next_target_position - prev_target_position - 1));
        prev_target_position = next_target_position;
        next_target_position = cmdStr.find('.', prev_target_position + 1);
    }

    size_t operation_position_end = cmdStr.find('|');

    std::string operation = cmdStr.substr(prev_target_position + 1,  cmdStr.find('|') - prev_target_position - 1);

    auto argument_parser = [=]
    {
        std::vector<std::string>arguments;

        size_t prev_argument_position =  operation_position_end;
        size_t next_argument_position = cmdStr.find('|', operation_position_end + 1);

        while(next_argument_position != std::string::npos)
        {
            arguments.emplace_back(cmdStr.substr(prev_argument_position + 1, next_argument_position - prev_argument_position - 1));
            prev_argument_position = next_argument_position;
            next_argument_position = cmdStr.find('|', prev_argument_position + 1);
        }

        arguments.emplace_back(cmdStr.substr(prev_argument_position + 1));

        return arguments;
    };

    command->m_Target = targets;
    command->m_Operation = operation;
    command->m_Arguments = argument_parser();

    return command;
}

const std::vector<std::string> &Command::GetTarget() const
{
    return m_Target;
}

const std::string &Command::GetOperation() const
{
    return m_Operation;
}

const std::vector<std::string> &Command::GetArguments() const
{
    return m_Arguments;
}

const int32_t &Command::GetTimeLimit() const
{
    return m_TimeLimit;
}

//int main()
//{
//    auto command = Command::FromCommandString("server.robot.test_basic|24,32");
//
//    for(const auto& target : command->GetTarget())
//        printf("Target: %s \n", target.c_str());
//
//    printf("Operation: %s \n", command->GetOperation().c_str());
//
//    for(const auto&argument : command->GetArguments())
//        printf("Argument: %s \n", argument.c_str());
//}

