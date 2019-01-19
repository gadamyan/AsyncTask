
#include "AbstractCommandHandler.hpp"

using namespace async_task;

AbstractCommandHandler::AbstractCommandHandler(std::weak_ptr<AsyncTaskService> service)
: m_service(service)
{
}
