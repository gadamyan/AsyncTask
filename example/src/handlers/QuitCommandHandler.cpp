
#include "QuitCommandHandler.hpp"

CommandResult QuitCommandHandler::handle(const std::vector<std::string>& words)
{
    m_service->remove_all_tasks();
    return CommandResult { "", true };
}
