
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