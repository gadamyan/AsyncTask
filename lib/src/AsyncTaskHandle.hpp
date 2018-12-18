
#pragma once

#include "TaskHandle.hpp"
#include "Task.hpp"

#include <thread>
#include <mutex>

namespace async_task {

class AsyncTaskHandle : public TaskHandle
{
public:
    AsyncTaskHandle(std::unique_ptr<Task> task);
    ~AsyncTaskHandle();

    void pause() override;
    void resume() override;
    void cancel() override;
    TaskState get_state() const override;
    std::string get_id() const override;
    std::string get_type_id() const override;

private:
    const std::unique_ptr<Task> m_task;
    TaskState m_state;
    std::condition_variable m_condition;
    std::mutex m_waiting_mutex;
    std::recursive_mutex m_state_mutex;
    std::thread m_thread;

private:
    void run_task();
    bool should_continue();
};

}
