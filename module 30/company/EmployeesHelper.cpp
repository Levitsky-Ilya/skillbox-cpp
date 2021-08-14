//
// Created by leviz on 13.08.2021.
//

#include "EmployeesHelper.h"

void managersEmploymentHelper(Ceo& ceo) {
    assert(ceo.m_managers.empty());

    int employeesCount;

    std::cout << "Enter a number of working groups in a company.\n";
    std::cin >> employeesCount;
    ceo.employManagers(employeesCount);
    std::cout << "CEO employed " << employeesCount << " manager(s)).\n";
}

void workersEmploymentHelper(Ceo& ceo) {
    assert(!ceo.m_managers.empty());

    int employeesCount;

    for (auto& manager : ceo.m_managers) {
        int groupId = manager->m_employeeId;
        std::cout << "Enter a number of workers in group #" << groupId << ".\n";
        std::cin >> employeesCount;
        manager->employWorkers(employeesCount);
        std::cout << "Manager #" << groupId << " employed " << employeesCount << " worker(s)).\n";
    }
}