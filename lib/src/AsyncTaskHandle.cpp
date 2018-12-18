
#include "AsyncTaskHandle.hpp"

using namespace async_task;

AsyncTaskHandle::AsyncTaskHandle(std::unique_ptr<Task> task)
: m_task(std::move(task))
, m_state(TaskState::RUNNING)
{
    m_task->set_continue_func([this](){ return should_continue(); });
    m_thread = std::thread([this](){ run_task(); });
}

AsyncTaskHandle::~AsyncTaskHandle()
{
    cancel();
    m_thread.join();
}

void AsyncTaskHandle::pause()
{
    std::lock_guard<std::recursive_mutex> lock(m_state_mutex);
    if (m_state == TaskState::RUNNING)
    {
        m_state = TaskState::PAUSED;
    }
}

void AsyncTaskHandle::resume()
{
    std::lock_guard<std::recursive_mutex> lock(m_state_mutex);
    if (m_state == TaskState::PAUSED)
    {
        m_state = TaskState::RUNNING;
        m_condition.notify_one();
    }
}

void AsyncTaskHandle::cancel()
{
    std::lock_guard<std::recursive_mutex> lock(m_state_mutex);
    if (m_state == TaskState::RUNNING)
    {
        m_state = TaskState::CANCELLED;
    }
    else if (m_state == TaskState::PAUSED)
    {
        resume();
        m_state = TaskState::CANCELLED;
    }
}

TaskState AsyncTaskHandle::get_state() const
{
    return m_state;
}

std::string AsyncTaskHandle::get_id() const
{
    return std::to_string(std::hash<std::thread::id>()(m_thread.get_id()));
}

void AsyncTaskHandle::run_task()
{
    m_task->run();
    if (m_state != TaskState::CANCELLED)
    {
        m_state = TaskState::COMPLETED;
    }
}

bool AsyncTaskHandle::should_continue()
{
    std::unique_lock<std::recursive_mutex> state_lock(m_state_mutex);
    if (m_state == TaskState::PAUSED)
    {
        std::unique_lock<std::mutex> waiting_lock(m_waiting_mutex);
        state_lock.unlock();
        m_condition.wait(waiting_lock, [this](){ return m_state != TaskState::PAUSED; });
        waiting_lock.unlock();
    }
    return m_state != TaskState::CANCELLED;
}

std::string AsyncTaskHandle::get_type_id() const
{
    return m_task->get_type_id();
}
