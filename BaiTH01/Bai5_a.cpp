#include <iostream>
using namespace std;
const int MAXCOLS = 100;

void inputArr2D(int arr[][MAXCOLS], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
}