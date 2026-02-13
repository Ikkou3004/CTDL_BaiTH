#include <iostream>
using namespace std;


void appendDynamicArr(int* &arr, int &n, int x) {
    int newSize = n + 1;
    int* newArr = new int[newSize];

    for(int i = 0; i < n; i++) {
        newArr[i] = arr[i];
    }

    newArr[n] = x;

    if (n > 0) delete[] arr; 
    arr = newArr;
    n = newSize;
}