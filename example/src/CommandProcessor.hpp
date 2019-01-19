
#pragma once

#include "handlers/CommandResult.hpp"
#include "AsyncTaskService.hpp"
#include "handlers/AbstractCommandHandler.hpp"

#include <map>
#include <string>

class CommandProcessor
{
public:
    explicit CommandProcessor(std::weak_ptr<async_task::AsyncTaskService> service);
    CommandResult process_command(const std::string& input_line);

private:
    const std::weak_ptr<async_task::AsyncTaskService> m_service;
    std::map<std::string, std::unique_ptr<AbstractCommandHandler>> m_all_commands;
};
