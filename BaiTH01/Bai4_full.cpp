#include <iostream>
using namespace std;

// Cau a
int* inputDynamicArr(int n) {
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "Nhap phan tu: " << i << ": ";
        cin >> arr[i];
    }
    return arr;
}

// Cau b
void printDynamicArr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Cau c
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

// Main
int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    int* arr = inputDynamicArr(n);

    cout << "Mang vua nhap: ";
    printDynamicArr(arr, n);

    int x;
    cout << "Nhap so can them: ";
    cin >> x;
    appendDynamicArr(arr, n, x);

    cout << "Mang sau khi them: ";
    printDynamicArr(arr, n);

    delete[] arr;
    return 0;
}