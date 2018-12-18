
#include "MockTask.hpp"
#include "AsyncTaskService.hpp"

#include <gtest/gtest.h>

using namespace async_task;

struct AsyncTaskServiceFixture : public ::testing::Test
{
    AsyncTaskService service;
};

TEST_F(AsyncTaskServiceFixture, validate_schedule_task)
{
    const auto handle = service.schedule_task(std::make_unique<MockTask>());
    ASSERT_TRUE(handle);
    ASSERT_EQ(handle->get_state(), TaskState::RUNNING);
}

TEST_F(AsyncTaskServiceFixture, validate_get_task_with_id)
{
    const auto handle = service.schedule_task(std::make_unique<MockTask>());
    const auto handle_copy = service.get_task_with_id(handle->get_id());
    ASSERT_EQ(handle, handle_copy);
    ASSERT_EQ(service.get_task_with_id("AAA"), nullptr);
}

TEST_F(AsyncTaskServiceFixture, validate_get_all_task_handles)
{
    std::vector<std::shared_ptr<TaskHandle>> container;
    for (int i = 0; i < 10; ++i)
    {
        container.push_back(service.schedule_task(std::make_unique<MockTask>()));
    }
    auto all_task_handles = service.get_all_task_handles();
    for (const auto& item : container)
    {
        ASSERT_NE(std::find(all_task_handles.cbegin(), all_task_handles.cend(), item),
                  all_task_handles.cend());
    }
}

TEST_F(AsyncTaskServiceFixture, validate_remove_all_tasks)
{
    std::vector<std::shared_ptr<TaskHandle>> container;
    for (int i = 0; i < 10; ++i)
    {
        container.push_back(service.schedule_task(std::make_unique<MockTask>()));
    }
    service.remove_all_tasks();
    for (const auto& item : container)
    {
        ASSERT_EQ(service.get_task_with_id(item->get_id()), nullptr);
    }
}
