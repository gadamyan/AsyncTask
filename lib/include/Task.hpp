
#pragma once

#include <functional>
#include <string>

namespace async_task {

class Task
{
public:
    explicit Task(const std::string& type_id);
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;
    Task(Task&& other) = delete;
    Task& operator=(Task&& other) = delete;
    virtual ~Task() = default;

    void set_continue_func(std::function<bool()>&& continue_func);
    bool should_continue();
    std::string get_type_id() const;

    virtual void run() = 0;

private:
    std::function<bool()> m_continue_func;
    const std::string m_type_id;
};

}
