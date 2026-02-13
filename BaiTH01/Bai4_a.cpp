#include <iostream>
using namespace std;

int* inputDynamicArr(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "Nhap phan tu: " << i << ": ";
        cin >> arr[i];
    }
    return arr;
}