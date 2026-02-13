#include <iostream>
using namespace std;

int countArr(int a[], int n, int b[], int d[]) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        bool exists = false;

        for(int j = 0; j < count; j++) {
            if(a[i] == b[j]) {
                d[j]++;
                exists = true;
                break;
            }
        }
        if(!exists) {
            b[count] = a[i];
            d[count] = 1;
            count++;
        }
    }
    return count;
}

int main() {
    int a[] = {4, 3, 1, 3, 4, 5, 1};
    int b[10], d[10];
    int k = countArr(a, 7, b, d);
    for(int i=0; i<k; i++) 
        cout << b[i] << " xuat hien " << d[i] << " lan" << endl;
    return 0;
}