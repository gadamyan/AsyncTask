
#include "TimerTask.hpp"

#include <thread>
#include <chrono>

TimerTask::TimerTask(int time_seconds)
: Task("timer")
, m_time_seconds(time_seconds)
{
}

void TimerTask::run()
{
    for (int i = 0; i < m_time_seconds && should_continue(); ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
