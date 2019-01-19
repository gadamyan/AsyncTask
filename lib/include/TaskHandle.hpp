
#pragma once

#include <string>

namespace async_task {

/**
 * State of the task.
 */
enum class TaskState
{
    RUNNING,
    PAUSED,
    CANCELLED,
    COMPLETED
};

/**
 * Handle to the task. It allows the user to manage a single task.
 */
class TaskHandle
{
public:
    TaskHandle() = default;
    TaskHandle(const TaskHandle&) = delete;
    TaskHandle& operator=(const TaskHandle&) = delete;
    virtual ~TaskHandle() = default;

    /**
     * Pauses the task.
     */
    virtual void pause() = 0;

    /**
     * Resumes the task that was paused.
     */
    virtual void resume() = 0;

    /**
     * Cancels the task.
     */
    virtual void cancel() = 0;

    /**
     * Returns the state of the task.
     *
     * \return Task state.
     */
    virtual TaskState get_state() const = 0;

    /**
     * Returns the unique identifier of the task.
     *
     * \return Task id.
     */
    virtual std::string get_id() const = 0;

    /**
     * Returns the identifier of the task type.
     *
     * \return Task type id.
     */
    virtual std::string get_type_id() const = 0;
};

}
