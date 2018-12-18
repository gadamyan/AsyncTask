
#pragma once

#include "Task.hpp"

#include <string>

class FileWriterTask : public async_task::Task
{
public:
    explicit FileWriterTask(const std::string& file_name);
    void run() override;

private:
    const std::string m_file_name;
};
