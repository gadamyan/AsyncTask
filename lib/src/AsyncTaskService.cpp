
#include "AsyncTaskService.hpp"
#include "AsyncTaskHandle.hpp"
#include <algorithm>

using namespace async_task;

std::shared_ptr<TaskHandle> AsyncTaskService::schedule_task(std::unique_ptr<Task> task)
{
    auto task_handle = std::make_shared<AsyncTaskHandle>(std::move(task));
    m_task_map[task_handle->get_id()] = task_handle;
    return task_handle;
}

std::shared_ptr<TaskHandle> AsyncTaskService::get_task_with_id(const std::string& id) const
{
    const auto it = m_task_map.find(id);
    if (it != m_task_map.cend())
    {
        return it->second;
    }
    return nullptr;
}

std::vector<std::shared_ptr<TaskHandle>> AsyncTaskService::get_all_task_handles() const
{
    std::vector<std::shared_ptr<TaskHandle>> result(m_task_map.size());
    std::transform(m_task_map.cbegin(), m_task_map.cend(), result.begin(),
                   [](const auto& pair){ return pair.second; });
    return result;
}

void AsyncTaskService::remove_all_tasks()
{
    for (auto& pair : m_task_map)
    {
        pair.second->cancel();
    }
    m_task_map.clear();
}
