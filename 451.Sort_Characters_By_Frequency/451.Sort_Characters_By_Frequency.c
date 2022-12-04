typedef struct alph {
    char c;
    int freq;
} ALPH;

int cmp(const void* a, const void* b) {
    return ((ALPH*)b)->freq - ((ALPH*)a)->freq;
}

char* frequencySort(char* s) {
    ALPH count[62] = { { '0', 0 } };
    char* result = calloc(strlen(s) + 1, sizeof(char));
    // Initialize
    for (int i = 0; i < 26; i++)
        count[i].c = i + 'A';
    for (int i = 26; i < 52; i++)
        count[i].c = i + 'a' - 26;
    for (int i = 52; i < 62; i++)
        count[i].c = i + '0' - 52;
    // Count frequency
    while (*s != '\0') {
        if (*s >= 'a')
            count[*s++ - 'a' + 26].freq++;
        else if (*s >= 'A')
            count[*s++ - 'A'].freq++;
        else
            count[*s++ - '0' + 52].freq++;
    }
    // Sort alpabetics by frequency
    qsort(count, 62, sizeof(ALPH), cmp);
    // Assign character by frequency
    char* tmp = result;
    for (int i = 0; i < 62; i++) {
        for (int j = 0; j < count[i].freq; j++)
            *tmp++ = count[i].c;
    }
    result[strlen(result)] = '\0';
    return result;
}