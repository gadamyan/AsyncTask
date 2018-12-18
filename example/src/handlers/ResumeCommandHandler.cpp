
#include "ResumeCommandHandler.hpp"

CommandResult ResumeCommandHandler::handle(const std::vector<std::string>& words)
{
    switch (words.size()) {
        case 1:
            return CommandResult { "Too few arguments for the resume command", false };
        case 2:
            return handle_single_arg(words.back());
        default:
            break;
    }
    return CommandResult { "Too many arguments for the resume command", false };
}

CommandResult ResumeCommandHandler::handle_single_arg(const std::string& arg) const
{
    auto handle = m_service->get_task_with_id(arg);
    if (handle)
    {
        handle->resume();
        return CommandResult { "Resumed task with id " + handle->get_id(), false };
    }
    return CommandResult { "There is no task with id " + arg, false };
}
