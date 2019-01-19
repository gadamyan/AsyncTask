
#pragma once

#include "Task.hpp"

#include <string>

class TimerTask : public async_task::Task
{
public:
    explicit TimerTask(int time_seconds);
    void run() override;

private:
    const int m_time_seconds;
};
