#include <iostream>
using namespace std;

bool findArr(int a[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(a[i] == x) return true;
    }
    return false;
}

int main() {
    int a[] = {1, 5, 9, 2};
    int x = 5;
    if(findArr(a, 4, x)) cout << "So Nguyen la: " << x;
    else cout << "Khong co " << x;
    return 0;
}