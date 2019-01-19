
#pragma once

#include <functional>
#include <string>

namespace async_task {

/**
 * Task that needs to be executed asynchronouly.
 * The user needs to extend this class and override the run function.
 */
class Task
{
public:
    /**
     * Constructor
     *
     * \param type_id Type identifier of the task.
     */
    explicit Task(const std::string& type_id);
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;
    virtual ~Task() = default;

    /**
     * Needs to be called inside of the loop in order to check
     * wether the task is allowed to continue.
     * If the task was cancelled then this function will return false,
     * in that case user needs to cancel the loop.
     *
     * \return True if the task is not cancelled, false otherwise.
     */
    bool should_continue();

    /**
     * A virtual function that needs to be overriden by the user.
     * In the overriden function the user needs to crate a loop.
     */
    virtual void run() = 0;

    void set_continue_func(std::function<bool()>&& continue_func);
    std::string get_type_id() const;

private:
    std::function<bool()> m_continue_func;
    const std::string m_type_id;
};

}
