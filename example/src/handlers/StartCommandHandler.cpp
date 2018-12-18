
#include "StartCommandHandler.hpp"
#include "../FileWriterTask.hpp"
#include "../TimerTask.hpp"

CommandResult StartCommandHandler::handle(const std::vector<std::string>& words)
{
    switch (words.size()) {
        case 1:
            return create_timer_task();
        case 2:
            return handle_single_arg(words.back());
        default:
            break;
    }
    return CommandResult { "Too many arguments for the started command", false };
}

CommandResult StartCommandHandler::create_file_writer_task()
{
    const auto file_name = "file" + std::to_string(m_text_file_counter) + ".txt";
    ++m_text_file_counter;
    const auto handle = m_service->schedule_task<FileWriterTask>(file_name);
    return CommandResult { "Started task with id " + handle->get_id(), false };
}

CommandResult StartCommandHandler::create_timer_task() const
{
    const auto handle = m_service->schedule_task<TimerTask>(30);
    return CommandResult { "Started task with id " + handle->get_id(), false };
}

CommandResult StartCommandHandler::handle_single_arg(const std::string& arg)
{
    if (arg == "timer")
    {
        return create_timer_task();
    }
    else if (arg == "file_writer")
    {
        return create_file_writer_task();
    }
    return CommandResult { "There is no task with task type " + arg, false };
}
