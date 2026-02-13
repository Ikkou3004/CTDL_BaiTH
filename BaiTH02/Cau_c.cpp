int countFirstName(struct Student list[], int n) {
    int count = 0;
    string target = "Nguyen";
    for (int i = 0; i < n; i++) {
        if (list[i].name.find(target) == 0) {
            count++;
        }
    }
    return count;
}
