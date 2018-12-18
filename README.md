## Project description:
A C++ library that allows the user to manage an arbitrary number of asynchronous tasks.
The library allows users to schedule tasks to be run asynchronously and pause, resume and stop them.
The library also allows the user to query the status of a given task.

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

## Generate build files:
IMPORTANT: Cmake version 3.12.2 or higher is needed to generate the project.
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

### Run executables:
After the project is generated and compiled you will be able to run the executables.
To run the example application from the command line.
From the build directory:

    ./example/example_app

To run the test application and see the test results.

    ./test/async_task_test

### Generate Xcode project:
To generate Xcode project from the command line.
From the project root:

    ./build_xcode.cmake

Xcode project should be created in build_xcode folder.
Now, to open the project in Xcode editor.

    open build_xcode/AsyncTask.xcodeproj
