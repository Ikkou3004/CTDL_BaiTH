#include <iostream>
using namespace std;
const int MAXCOLS = 100;

void addArr2D(int a[][MAXCOLS], int b[][MAXCOLS], int m, int n, int c[][MAXCOLS]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}