#include <iostream>
#include <ctime>
#include <utility>
#include <vector>

struct Task {
    std::string name;
    std::time_t startTime;
    std::time_t duration;
};

struct TasksState {
    std::vector<Task> tasks;
    Task currentTask;
    bool taskRunning = false;
};

void endTask(TasksState &tasksState) {
    Task &currentTask = tasksState.currentTask;
    currentTask.duration = std::time(nullptr) - currentTask.startTime;
    tasksState.tasks.push_back(currentTask);
    tasksState.taskRunning = false;
    std::cout << "Task " << currentTask.name << " finished.\n";
}

void beginTask(TasksState &tasksState) {
    if (tasksState.taskRunning) {
        endTask(tasksState);
    }
    std::string taskName;
    std::cout << "Enter new task name: ";
    std::cin >> taskName;
    tasksState.currentTask.name = taskName;
    tasksState.currentTask.startTime = std::time(nullptr);
    tasksState.taskRunning = true;
    std::cout << "Task " << taskName << " started.\n";
}

void displayStatus(TasksState &tasksState) {
    int i = 0;
    for (const Task &task : tasksState.tasks) {
        std::cout << "Task " << i++ << ": " << task.name << ". Working time: " << task.duration << ".\n";
    }
    if (tasksState.taskRunning) {
        std::cout << "Running task: " << tasksState.currentTask.name << ".\n";
    }
}

int main() {
    TasksState tasksState;
    std::string command;
    std::cout << "** Welcome to Task Monitoring Program **\n"
                 "Enter \"begin\" to begin a new task (and end previous task).\n"
                 "Enter \"end\" to finish the current task.\n"
                 "Enter \"status\" to display all finished and current tasks.\n"
                 "Enter \"exit\" to exit Task Monitoring Program.\n" << std::endl;

    while (command != "exit") {
        std::cin >> command;
        if (command == "begin") {
            beginTask(tasksState);
        } else if (command == "end") {
            endTask(tasksState);
        } else if (command == "status") {
            displayStatus(tasksState);
        } else if (command == "exit") {
            std::cout << "Exiting.\n";
        } else {
            std::cout << "Unknown command. Enter again.\n";
        }
    }
    return 0;
}
