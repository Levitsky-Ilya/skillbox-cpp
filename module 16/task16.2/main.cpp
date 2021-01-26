#include <iostream>
#include <vector>

void printVector(std::vector<float> vec) {
    for (float element : vec)
        std::cout << element << " ";
}

int main() {
    std::vector<float> prices = {2.5, 4.25, 3.0, 10.0};
    int numProducts = prices.size();
    std::cout << "The prices are: ";
    printVector(prices);

    // This portion of code allows a user to input purchases indices.
    //std::cout << "\nEnter your purchases by selecting numbers from 0 to " <<
    //    numProducts - 1 << ". Enter -1 to finish your shopping session. \n";
    //float total = 0.f;
    //while (true) {
    //    int purchaseIndex;
    //    std::cout << ">";
    //    std::cin >> purchaseIndex;
    //    if (purchaseIndex < -1 || purchaseIndex >= numProducts)
    //        std::cout << "No such product! Enter another one.\n";
    //    else if (purchaseIndex == -1)
    //        break;
    //    else
    //        total += prices[purchaseIndex];
    //};

    // This portion of code contains preselected purchases indices.
    std::vector<float> purchaseIndices = {1, 0, 1, 1, 0, 1, 1, 3, 0, 2};

    std::cout << "\n The purchases are: ";
    printVector(purchaseIndices);

    float total = 0.f;
    for (int purchaseIndex : purchaseIndices)
        total += prices[purchaseIndex];



    std::cout << "\nThe total price is " << total << "\n";
}
