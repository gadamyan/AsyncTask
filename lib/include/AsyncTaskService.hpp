
#pragma once

#include "Task.hpp"
#include "TaskHandle.hpp"

#include <memory>
#include <map>
#include <vector>

namespace async_task {

/**
 * A service that allows the user to create manage an arbitrary number of asynchronous tasks.
 */
class AsyncTaskService final
{
public:
    AsyncTaskService() = default;
    AsyncTaskService(const AsyncTaskService&) = delete;
    AsyncTaskService& operator=(const AsyncTaskService&) = delete;
    AsyncTaskService(AsyncTaskService&&) = default;
    AsyncTaskService& operator=(AsyncTaskService&&) = default;

    /**
     * Template function that schedules a generic task and returns a handle to it.
     *
     * \param args Arguments of the constructor of the task that needs to be scheduled.
     * \return Handle to the task.
     */
    template<typename T, typename ...Args>
    std::shared_ptr<TaskHandle> schedule_task(Args&&... args)
    {
        return schedule_task(std::make_unique<T>(std::forward<Args>(args)...));
    }

    /**
     * Schedules a task and returns a handle to it.
     *
     * \param task Task that needs to be scheduled.
     * \return Handle to the task.
     */
    std::shared_ptr<TaskHandle> schedule_task(std::unique_ptr<Task> task);

    /**
     * Returns the handle for the specified task id.
     *
     * \param id Task id.
     * \return Handle to the task.
     */
    std::shared_ptr<TaskHandle> get_task_with_id(const std::string& id) const;

    /**
     * Returns all the scheduled task handles.
     *
     * \return A vector of task handles.
     */
    std::vector<std::shared_ptr<TaskHandle>> get_all_task_handles() const;

    /**
     * Removes all the scheduled tasks.
     */
    void remove_all_tasks();

private:
    std::map<std::string, std::shared_ptr<TaskHandle>> m_task_map;
};

}
