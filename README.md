## Project description:
A C++ library that allows the user to manage an arbitrary number of asynchronous tasks.
The library allows users to schedule tasks to be run asynchronously and pause, resume and stop them.
The library also allows the user to query the status of a given task.

## API uasge:

A task has to extend the async_task::Task abstract class and override the *run* method.
In the loop of the implementation function there should be a call of the *should_continue* function,
It is needed to cancel the loop and be able to pause or cancel the task.

    class SampleTask : public async_task::Task
    {
    public:
        SampleTask(...);
        void run() override
        {
            while (should_continue() && ...)
            {
                ...
            }
        }
    };

AsyncTaskService class gives an ability to create and manage arbitrary number of asynchronous tasks.
*schedule_task* function creates and schedules a task and returns a handle to it.
Having the task handle, it is possible to pause, resume, cancel and check the state of the task.

    async_task::AsyncTaskService service;
    auto handle = service.schedule_task<SampleTask>(...);
    handle->get_state();
    handle->pause();
    handle->resume();
    handle->cancel();

## Example application usage:
The example application uses the AsyncTask library to schedule and manage tasks.
Currently only tow types of tasks are supported.
1. *timer*. The timer task is the default task, it starts a timer with 30 seconds interval.
2. *file_writer*. The file writer task writes a random string into a file.

To print help message and instructions

    ./example_app --help

To start the example application and waits for instructions, start it without arguments

    ./example_app

Once the program is running, it will read instructions from the standard input.
These instructions have the following format:

- start starts the default task and prints its ID.
- start <task_type> Starts a task of a given type and and prints its ID. there are two types of supported tasks *timer* and *file_writer*.
- pause <task_id> pauses the task with the given id and prints a confirmation message.
- resume <task_id> resumes task with the given id (if paused) and print a confirmation message.
- stop <task_id> stop the task with the given id (if not stopped) and prints a confirmation message.
- status prints the task type, id and the status (paused, running, stopped, completed) for each task.
- status <task_id> As above, but for a single task.
- quits gracefully shut down.

## Dependencies:
- C++14 compiler
- Cmake version 3.12.2 or higher

## Generate build files:
To generate makefiles from the command line.
From the project root:

    mkdir build
    cd build
    cmake ..

Makefiles should be created.
Now, to compile the executables and link them.

    make

To run all tests easily.

    make test

## Rsun executables:
After the project is generated and compiled you will be able to run the executables.
To run the example application from the command line.
From the build directory:

    ./example/example_app

To run the test application and see the test results.

    ./test/async_task_test

### Generate Xcode project:
To generate Xcode project from the command line.
From the project root:

    mkdir build_xcode
    cd build_xcode
    cmake -G "Xcode" ..

Xcode project should be created in build_xcode folder.
Now, to open the project in Xcode editor.

    open AsyncTask.xcodeproj

### Generate Visual Studio project:
To generate Visual Studio project from the command line.
From the project root:

    mkdir build_vs
    cd build_vs
    cmake -G "Visual Studio 15 2017" ..

Visual Studio project should be created in build_vs folder.
Now, to open the project in Visual Studio editor.

    open AsyncTask.sln
