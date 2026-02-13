#include <iostream>
using namespace std;

float avgArr(int a[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }

    if (n > 0) return (float)sum / n;
    return 0;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "Trung binh cong la: " << avgArr(a, n);
    return 0;
}