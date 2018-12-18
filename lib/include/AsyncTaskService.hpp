
#pragma once

#include "Task.hpp"
#include "TaskHandle.hpp"

#include <memory>
#include <map>
#include <vector>

namespace async_task {

class AsyncTaskService final
{
public:
    template<typename T, typename ...Args>
    std::shared_ptr<TaskHandle> schedule_task(Args&&... args)
    {
        return schedule_task(std::make_unique<T>(std::forward<Args>(args)...));
    }

    std::shared_ptr<TaskHandle> schedule_task(std::unique_ptr<Task> task);

    std::shared_ptr<TaskHandle> get_task_with_id(const std::string& id) const;

    std::vector<std::shared_ptr<TaskHandle>> get_all_task_handles() const;

    void remove_all_tasks();

private:
    std::map<std::string, std::shared_ptr<TaskHandle>> m_task_map;
};

}
