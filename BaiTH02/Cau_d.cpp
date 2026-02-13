string convertName(string name) {
    int lastSpace = name.rfind(' ');
    if (lastSpace == -1) return name;
    string ten = name.substr(lastSpace + 1);
    string hoDem = name.substr(0, lastSpace);
    return ten + " " + hoDem;
}

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