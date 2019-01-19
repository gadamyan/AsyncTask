
#include "CommandProcessor.hpp"

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
    using IteratorType = std::istream_iterator<std::string>;
    return { IteratorType(istring_strem), IteratorType() };
}
}

CommandProcessor::CommandProcessor(std::weak_ptr<async_task::AsyncTaskService> service)
: m_service(std::move(service))
{
    m_all_commands.emplace("start", std::make_unique<StartCommandHandler>(m_service));
    m_all_commands.emplace("pause", std::make_unique<PauseCommandHandler>(m_service));
    m_all_commands.emplace("resume", std::make_unique<ResumeCommandHandler>(m_service));
    m_all_commands.emplace("stop", std::make_unique<StopCommandHandler>(m_service));
    m_all_commands.emplace("status", std::make_unique<StatusCommandHandler>(m_service));
    m_all_commands.emplace("quit", std::make_unique<QuitCommandHandler>(m_service));
}

CommandResult CommandProcessor::process_command(const std::string& input_line)
{
    const std::vector<std::string> words = split_string(input_line);
    const std::string command = words.front();
    auto it = m_all_commands.find(command);
    if (it != m_all_commands.cend())
    {
        return it->second->handle(words);
    }
    return CommandResult { "Unknown command: " + command, false };

}
