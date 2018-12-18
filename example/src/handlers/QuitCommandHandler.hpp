
#pragma once

#include "AbstractCommandHandler.hpp"

class QuitCommandHandler : public AbstractCommandHandler
{
    using AbstractCommandHandler::AbstractCommandHandler;

public:
    CommandResult handle(const std::vector<std::string>& words) override;
};
