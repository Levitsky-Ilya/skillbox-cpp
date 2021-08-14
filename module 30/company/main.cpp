#include <iostream>

#include "Employees.h"
#include "EmployeesHelper.h"

int main() {
    std::cout << "CEO creates a company.\n";

    Ceo ceo;

    managersEmploymentHelper(ceo);
    workersEmploymentHelper(ceo);

    bool allGroupsBusy = false;
    while (!allGroupsBusy) {
        int order;
        std::cout << "Give an order identifier:\n";
        std::cin >> order;
        allGroupsBusy = ceo.giveOrder(order);
    }

    std::cout << "All groups in the company are busy.\n";

    return 0;
}
