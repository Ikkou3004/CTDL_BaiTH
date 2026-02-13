#include <iostream>
using namespace std;
const int MAXCOLS = 100;

void multiplyArr2D(int a[][MAXCOLS], int b[][MAXCOLS], int m, int p, int n, int c[][MAXCOLS]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            c[i][j] = 0;
            for(int k = 0; k < p; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}