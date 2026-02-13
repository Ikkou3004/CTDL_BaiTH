#include <iostream>
using namespace std;

void sortArr(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int a[] = {5, 2, 8, 1};
    sortArr(a, 4);
    cout << "Mang la: ";
    for(int i=0; i<4; i++) cout << a[i] << " ";
    return 0;
}