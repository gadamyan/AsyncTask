
#pragma once

#include "AbstractCommandHandler.hpp"

class StopCommandHandler : public AbstractCommandHandler
{
    using AbstractCommandHandler::AbstractCommandHandler;
    
public:
    CommandResult handle(const std::vector<std::string>& words) override;

private:
    CommandResult handle_single_arg(const std::string& arg) const;
};
