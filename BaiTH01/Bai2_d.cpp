#include <iostream>
using namespace std;


int mergeArr(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
    
    return k;
}

int main() {
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6, 8};
    int c[100];
    int sizeC = mergeArr(a, 3, b, 4, c);
    cout << "Mang la: ";
    for(int i=0; i<sizeC; i++) cout << c[i] << " ";
    return 0;
}