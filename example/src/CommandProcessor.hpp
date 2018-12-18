
#pragma once

#include "handlers/CommandResult.hpp"

#include <string>

class CommandProcessor
{
public:
    CommandResult process_command(const std::string& input_line);
};
