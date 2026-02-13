#include <iostream>
using namespace std;
const int MAXCOLS = 100;

void maxArr2D(int arr[][MAXCOLS], int m, int n, int &rowMax, int &colMax) {
    int maxVal = arr[0][0];
    rowMax = 0;
    colMax = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] > maxVal) {
                maxVal = arr[i][j];
                rowMax = i;
                colMax = j;
            }
        }
    }
}