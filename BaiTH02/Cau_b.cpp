int appendStudent(struct Student list[], int n, struct Student s) {
    list[n] = s;
    return n + 1;