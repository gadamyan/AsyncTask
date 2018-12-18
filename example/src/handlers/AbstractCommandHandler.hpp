
#pragma once

#include "CommandResult.hpp"
#include "AsyncTaskService.hpp"

#include <string>
#include <vector>

class AbstractCommandHandler
{
public:
    AbstractCommandHandler(std::shared_ptr<async_task::AsyncTaskService> service);
    virtual CommandResult handle(const std::vector<std::string>& words) = 0;
    virtual ~AbstractCommandHandler() = default;

protected:
    const std::shared_ptr<async_task::AsyncTaskService> m_service;
};
