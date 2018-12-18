
#include "StatusCommandHandler.hpp"

using namespace async_task;

namespace {

std::string task_status_to_string(TaskState status)
{
    switch (status)
    {
        case TaskState::RUNNING:
            return "running";

        case TaskState::PAUSED:
            return "paused";

        case TaskState::COMPLETED:
            return "completed";

        case TaskState::CANCELLED:
            return "cancelled";

        default:
            break;
    }
    assert(false);
    return "";
}

std::string get_status_comman_message(std::shared_ptr<TaskHandle> handle)
{
    const std::string state = task_status_to_string(handle->get_state());
    return "The task " + handle->get_type_id() + " with id " + handle->get_id() + " is " + state;
}
}

CommandResult StatusCommandHandler::handle(const std::vector<std::string>& words)
{
    switch (words.size()) {
        case 1:
            return handle_not_args();
        case 2:
            return handle_single_arg(words.back());
        default:
            break;
    }
    return CommandResult { "Too many arguments for the status command", false };
}

CommandResult StatusCommandHandler::handle_not_args() const
{
    const auto all_handles = m_service->get_all_task_handles();
    std::string result_test;
    for (const auto& handle : all_handles)
    {
        result_test += get_status_comman_message(handle) + "\n";
    }
    result_test = all_handles.empty() ? "There is no scheduled task" : result_test;
    return CommandResult { result_test, false };
}

CommandResult StatusCommandHandler::handle_single_arg(const std::string& arg) const
{
    const auto handle = m_service->get_task_with_id(arg);
    if (handle)
    {
        return CommandResult { get_status_comman_message(handle), false };
    }
    return CommandResult { "There is no task with id " + arg, false };
}
