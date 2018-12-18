
#include "Task.hpp"

using namespace async_task;

Task::Task(const std::string& type_id)
: m_type_id(type_id)
{
}

bool Task::should_continue()
{
    return m_continue_func();
}

void Task::set_continue_func(std::function<bool()>&& continue_func)
{
    m_continue_func = std::move(continue_func);
}

std::string Task::get_type_id() const
{
    return m_type_id;
}
