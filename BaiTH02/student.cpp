#include <iostream>
#include <string>
#include <fstream> // Thư viện đọc ghi file

using namespace std;

// --- ĐỊNH NGHĨA CẤU TRÚC DỮ LIỆU ---
struct Student {
    string name;
    int age;
    double gpa;
};

// --- CÁC HÀM QUẢN LÝ CƠ BẢN ---

// Hàm nhập thông tin 1 sinh viên
void inputStudent(struct Student &s) {
    cout << "Name: ";
    getline(cin, s.name);
    cout << "Age: ";
    cin >> s.age;
    cout << "GPA: ";
    cin >> s.gpa;
}

// Hàm in thông tin 1 sinh viên
void printStudent(struct Student s) {
    cout << "Name: " << s.name << " | Age: " << s.age << " | GPA: " << s.gpa << endl;
}

// Hàm nhập danh sách sinh viên
void inputListOfStudent(struct Student list[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap sinh vien thu " << i + 1 << " ---" << endl;
        // Xóa bộ nhớ đệm để tránh trôi lệnh nhập tên (thay cho fflush)
        cin.ignore();
        inputStudent(list[i]);
    }
}

// Hàm in danh sách sinh viên
void printListOfStudent(struct Student list[], int n) {
    cout << "\n---------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        printStudent(list[i]);
    }
    cout << "---------------------------------" << endl;
}

// Hàm tìm kiếm sinh viên theo tên
int findStudent(struct Student list[], int n, string name) {
    for (int i = 0; i < n; i++) {
        if (list[i].name == name)
            return i;
    }
    return -1;
}

// --- CÁC HÀM ĐỌC/GHI FILE ---

// Hàm ghi danh sách sinh viên ra file
void writeToFile(struct Student list[], int n, char* fname) {
    fstream out;
    out.open(fname, ios::out);
    for (int i = 0; i < n; i++) {
        // Ghi đúng định dạng có dấu cách sau dấu phẩy để khớp với hàm đọc
        out << list[i].name << ", " << list[i].age << ", " << list[i].gpa << endl;
    }
    out.close();
}

// Hàm đọc danh sách sinh viên từ file
int readFromFile(char *fname, struct Student list[]) {
    fstream fin;
    string s;
    int m, n, k = 0;

    fin.open(fname);
    if (!fin) return 0; // Trả về 0 nếu không mở được file

    while (getline(fin, s)) {
        if (s.empty()) continue;

        // Logic cắt chuỗi: Tên, Tuổi, GPA
        n = s.find(',');
        list[k].name = s.substr(0, n);

        m = s.find(',', n + 1);
        list[k].age = stoi(s.substr(n + 2, m - n - 2));
        list[k].gpa = stod(s.substr(m + 2));

        k++;
    }
    fin.close();
    return k; // Trả về số lượng đọc được
}

// --- CÁC HÀM BỔ SUNG (PHẦN NÂNG CAO) ---

// a) Hàm liệt kê sinh viên có GPA >= 8
void listOfGoodStudents(struct Student list[], int n) {
    cout << "\n>>> DANH SACH SINH VIEN GIOI (GPA >= 8):" << endl;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (list[i].gpa >= 8.0) {
            printStudent(list[i]);
            count++;
        }
    }
    if (count == 0) cout << "Khong co sinh vien nao." << endl;
}

// b) Hàm thêm một sinh viên vào cuối danh sách
int appendStudent(struct Student list[], int n, struct Student s) {
    list[n] = s;
    return n + 1; // Trả về kích thước mảng mới
}

// c) Hàm đếm số người họ Nguyen
int countFirstName(struct Student list[], int n) {
    int count = 0;
    string target = "Nguyen";
    for (int i = 0; i < n; i++) {
        // Kiểm tra xem tên có bắt đầu bằng chữ "Nguyen" không
        if (list[i].name.find(target) == 0) {
            count++;
        }
    }
    return count;
}

// Hàm phụ trợ: Đảo vị trí tên lên trước họ đệm để so sánh
string convertName(string name) {
    int lastSpace = name.rfind(' ');
    if (lastSpace == -1) return name;
    string ten = name.substr(lastSpace + 1);
    string hoDem = name.substr(0, lastSpace);
    return ten + " " + hoDem;
}

// d) Hàm sắp xếp danh sách theo tên (A-Z)
void sortVNName(struct Student list[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (convertName(list[i].name) > convertName(list[j].name)) {
                struct Student temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

// --- HÀM MAIN ---
int main() {
    struct Student m[100];
    int n = 0;
    char filename[] = "students.txt";

    // 1. Nhập danh sách ban đầu
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    inputListOfStudent(m, n);

    // 2. Ghi ra file
    writeToFile(m, n, filename);
    cout << "\n(Da ghi du lieu ra file students.txt)" << endl;

    // 3. Test chức năng: Liệt kê sinh viên giỏi
    listOfGoodStudents(m, n);

    // 4. Test chức năng: Thêm sinh viên mới
    cout << "\n>>> THEM 1 SINH VIEN MOI:" << endl;
    struct Student s_new;
    cin.ignore(); // Xóa bộ nhớ đệm trước khi nhập người mới
    inputStudent(s_new);
    n = appendStudent(m, n, s_new);
    cout << "Danh sach sau khi them:" << endl;
    printListOfStudent(m, n);

    // 5. Test chức năng: Đếm họ Nguyen
    cout << "\n>>> THONG KE HO NGUYEN:" << endl;
    cout << "So luong: " << countFirstName(m, n) << endl;

    // 6. Test chức năng: Sắp xếp theo tên
    cout << "\n>>> SAP XEP THEO TEN (A-Z):" << endl;
    sortVNName(m, n);
    printListOfStudent(m, n);

    return 0;
}