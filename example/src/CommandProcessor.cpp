
#include "CommandProcessor.hpp"

#include "AsyncTaskService.hpp"
#include "handlers/StartCommandHandler.hpp"
#include "handlers/PauseCommandHandler.hpp"
#include "handlers/ResumeCommandHandler.hpp"
#include "handlers/StopCommandHandler.hpp"
#include "handlers/StatusCommandHandler.hpp"
#include "handlers/QuitCommandHandler.hpp"

#include <vector>
#include <iterator>
#include <sstream>
#include <map>

using namespace async_task;

namespace {

std::vector<std::string> split_string(const std::string& input_line)
{
    std::istringstream istring_strem(input_line);
    return { std::istream_iterator<std::string>(istring_strem),
        std::istream_iterator<std::string>() };
}

std::map<std::string, std::unique_ptr<AbstractCommandHandler>>
    construct_command_map(std::shared_ptr<AsyncTaskService> service)
{
    std::map<std::string, std::unique_ptr<AbstractCommandHandler>> all_commands;
    all_commands.emplace("start", std::make_unique<StartCommandHandler>(service));
    all_commands.emplace("pause", std::make_unique<PauseCommandHandler>(service));
    all_commands.emplace("resume", std::make_unique<ResumeCommandHandler>(service));
    all_commands.emplace("stop", std::make_unique<StopCommandHandler>(service));
    all_commands.emplace("status", std::make_unique<StatusCommandHandler>(service));
    all_commands.emplace("quit", std::make_unique<QuitCommandHandler>(service));
    return all_commands;
}
}

CommandResult CommandProcessor::process_command(const std::string& input_line)
{
    auto service = std::make_shared<AsyncTaskService>();
    static auto all_commands = construct_command_map(service);
    const std::vector<std::string> words = split_string(input_line);
    auto it = all_commands.find(words.front());
    if (it != all_commands.cend())
    {
        return it->second->handle(words);
    }
    return CommandResult { "Unknown command: " + words.front(), false };

}
