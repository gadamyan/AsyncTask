
#include "StopCommandHandler.hpp"

CommandResult StopCommandHandler::handle(const std::vector<std::string>& words)
{
    switch (words.size()) {
        case 1:
            return CommandResult { "Too few arguments for the stop command", false };
        case 2:
            return handle_single_arg(words.back());
        default:
            break;
    }
    return CommandResult { "Too many arguments for the stop command", false };
}

CommandResult StopCommandHandler::handle_single_arg(const std::string& arg) const
{
    auto handle = m_service.lock()->get_task_with_id(arg);
    if (handle)
    {
        handle->cancel();
        return CommandResult { "Stopped task with id " + handle->get_id(), false };
    }
    else
    {
        return CommandResult { "There is no task with id " + arg, false };
    }
}
