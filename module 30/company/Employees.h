//
// Created by leviz on 13.08.2021.
//

#ifndef COMPANY_EMPLOYEES_H
#define COMPANY_EMPLOYEES_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>

enum Task {
    A,
    B,
    C
};

const int tasksCount = 3;

std::string taskToString(Task task);

class Employee {
public:

    Employee();

    int m_employeeId;
    static int employeesCount;
};

class Worker : public Employee {
public:

    Worker();

    void getTask(Task task);

    std::vector<Task> m_tasks;
};

class Manager : public Employee {
public:

    Manager();

    bool assignTasks(int order);

    void employWorkers(int workersCount);

    std::vector<Worker*> m_workers;
    int m_nextWorkerIndex;
    bool m_groupBusy;
};

class Ceo : public Employee {
public:

    Ceo();

    bool giveOrder(int order);

    void employManagers(int managersCount);

    std::vector<Manager*> m_managers;
};

#endif //COMPANY_EMPLOYEES_H
