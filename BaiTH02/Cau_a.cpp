void listOfGoodStudents(struct Student list[], int n) {
    cout << "\n>>> DANH SACH SINH VIEN GPA >= 8:" << endl;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (list[i].gpa >= 8.0) {
            printStudent(list[i]);
            count++;
        }
    }
    if (count == 0) cout << "Khong co sinh vien nao." << endl;
}