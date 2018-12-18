#pragma once

#include "Task.hpp"

namespace async_task {

class MockTask : public Task
{
public:
    explicit MockTask()
    : Task("MockTask")
    {
    }

    void run() override
    {
        while (should_continue() && !m_should_finish);
    }

    void finish()
    {
        m_should_finish = true;
    }

private:
    bool m_should_finish = false;
};

}
