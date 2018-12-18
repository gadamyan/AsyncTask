
#pragma once

#include "AbstractCommandHandler.hpp"

class StartCommandHandler : public AbstractCommandHandler
{
    using AbstractCommandHandler::AbstractCommandHandler;

public:
    CommandResult handle(const std::vector<std::string>& words) override;

private:
    CommandResult create_file_writer_task();
    CommandResult create_timer_task() const;
    CommandResult handle_single_arg(const std::string& arg);

private:
    int m_text_file_counter = 1;
};
