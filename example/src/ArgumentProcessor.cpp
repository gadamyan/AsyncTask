
#include "ArgumentProcessor.hpp"
#include "CommandProcessor.hpp"
#include "Utils.hpp"
#include <iostream>

ArgumentProcessor::ArgumentProcessor(int argc, char** argv)
{
    assert(argc != 0);
    switch (argc) {
        case 1:
            start_loop();
            return;
        case 2:
            process_single_arg(argv[1]);
            return;
        default:
            break;
    }
    std::cout << "Too many parameters" << std::endl;
}

void ArgumentProcessor::start_loop() const
{
    CommandProcessor processor;
    for (std::string input_line; std::getline(std::cin, input_line);)
    {
        const auto result = processor.process_command(input_line);
        if (!result.should_exit)
        {
            std::cout << result.responce << std::endl;
        }
        else
        {
            break;
        }
    }
}

void ArgumentProcessor::process_single_arg(const std::string& arg) const
{
    if (arg == std::string("--help"))
    {
        std::cout << utils::get_help_text() << std::endl;
    }
    else
    {
        std::cout << "Unknown parameter: " << arg << std::endl;
    }
}
