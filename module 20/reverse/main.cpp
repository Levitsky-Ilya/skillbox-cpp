#include <iostream>

int* reverse(int* arr) {
    int* result = (int*)malloc(10 * sizeof(int));
    for (int i = 9; i >= 0; i--) {
        result[i] = arr[9 - i];
    }
    return result;
}

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9,0};

    int* reversedArr = reverse(arr);

    for (int i = 0; i < 10; i++)
        std::cout << reversedArr[i] << " ";
}
