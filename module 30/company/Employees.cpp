//
// Created by leviz on 13.08.2021.
//

#include "Employees.h"

int Employee::employeesCount = 0;

std::string taskToString(Task task) {
    return (task == A) ? "A" : (task == B) ? "B" : "C";
}

/// Employee ///

Employee::Employee() : m_employeeId(employeesCount) {
    employeesCount++;
}

/// Worker ///

Worker::Worker() = default;

void Worker::getTask(Task task) {
    m_tasks.push_back(task);
    std::cout << "Worker #" << m_employeeId << " gets task " << taskToString(task) << "\n";
}

/// Manager ///

Manager::Manager() :
    m_workers(0),
    m_nextWorkerIndex(0),
    m_groupBusy(false) {}

bool Manager::assignTasks(int order) {
    assert(!m_workers.empty());

    int seed = order + m_employeeId;
    srand(seed);
    int tasksPerOrder = (rand() % m_workers.size()) + 1;

    for (int i = 0; i < tasksPerOrder; i++) {
        Task task = static_cast<Task>(rand() % tasksCount);
        m_workers[m_nextWorkerIndex]->getTask(task);
        if (m_nextWorkerIndex == m_workers.size() - 1) {
            m_nextWorkerIndex = 0;
            m_groupBusy = true;
        } else {
            m_nextWorkerIndex++;
        }
    }

    return m_groupBusy;
}

void Manager::employWorkers(int workersCount) {
    assert(m_workers.empty());
    assert(workersCount > 0);
    for (int i = 0; i < workersCount; i++) {
        m_workers.push_back(new Worker);
    }
}

/// CEO ///

Ceo::Ceo() = default;

bool Ceo::giveOrder(int order) {
    assert(!m_managers.empty());

    bool allGroupsBusy = true;
    for (const auto& manager : m_managers) {
        allGroupsBusy &= manager->assignTasks(order);
    }
    return allGroupsBusy;
}

void Ceo::employManagers(int managersCount) {
    assert(m_managers.empty());
    assert(managersCount > 0);
    for (int i = 0; i < managersCount; i++) {
        m_managers.push_back(new Manager);
    }
}

