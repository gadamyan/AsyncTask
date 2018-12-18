
#include "FileWriterTask.hpp"

#include <fstream>
#include <cstdio>
#include <random>

namespace {

std::string generate_text()
{
    static constexpr char count = 'z' - 'a';
    static std::random_device device;
    static std::default_random_engine generator(device());
    static std::uniform_int_distribution<char> distribution(0, count);

    std::string text;
    for (int i = 0; i < 120; ++i)
    {
        const char random_char = 'a' + distribution(generator);
        text += random_char;
    }
    return text;
}
}

FileWriterTask::FileWriterTask(const std::string& file_name)
: Task("file_writer")
, m_file_name(file_name)
{
}

void FileWriterTask::run()
{
    std::ofstream file(m_file_name);
    for (int i = 0; i < 1000000 && should_continue(); ++i)
    {
        file << generate_text() << std::endl;
    }
    std::remove(m_file_name.c_str());
}
