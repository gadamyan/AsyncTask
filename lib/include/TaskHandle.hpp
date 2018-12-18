
#pragma once

#include <string>

namespace async_task {

enum class TaskState
{
    RUNNING,
    PAUSED,
    CANCELLED,
    COMPLETED
};

class TaskHandle
{
public:
    TaskHandle() = default;
    TaskHandle(const TaskHandle&) = delete;
    TaskHandle& operator=(const TaskHandle&) = delete;
    virtual ~TaskHandle() = default;

    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void cancel() = 0;
    virtual TaskState get_state() const = 0;
    virtual std::string get_id() const = 0;
    virtual std::string get_type_id() const = 0;
};

}
