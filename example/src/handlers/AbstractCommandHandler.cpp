
#include "AbstractCommandHandler.hpp"

using namespace async_task;

AbstractCommandHandler::AbstractCommandHandler(std::shared_ptr<AsyncTaskService> service)
: m_service(service)
{
}
