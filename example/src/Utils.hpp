
#pragma once

#include <string>

namespace utils {

std::string get_help_text()
{
    return
    "The example application uses the AsyncTask library to schedule and manage tasks.\n"
    "Currently only tow types of tasks are supported.\n"
    "1. timer. The timer task is the default task, it starts a timer with 30 seconds interval.\n"
    "2. file_writer. The file writer task writes a random string into a file.\n\n"
    "Once the program is running, it will read instructions from the standard input.\n"
    "These instructions have the following format:\n\n"
    "- start starts the default task and prints its ID.\n"
    "- start <task_type> Starts a task of a given type and and prints its ID. there are two types of supported tasks timer and file_writer.\n"
    "- pause <task_id> pauses the task with the given id and prints a confirmation message.\n"
    "- resume <task_id> resumes task with the given id (if paused) and print a confirmation message.\n"
    "- stop <task_id> stop the task with the given id (if not stopped) and prints a confirmation message.\n"
    "- status prints the task type, id and the status (paused, running, stopped, completed) for each task.\n"
    "- status <task_id> As above, but for a single task.\n"
    "- quits gracefully shut down.\n";
}
}
