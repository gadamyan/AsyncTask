
#pragma once

#include <string>

class ArgumentProcessor
{
public:
    ArgumentProcessor(int argc, char** argv);

private:
    void start_loop() const;
    void process_single_arg(const std::string& arg) const;
};
