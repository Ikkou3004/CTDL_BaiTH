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