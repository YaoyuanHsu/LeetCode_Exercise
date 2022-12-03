#define ALP_SIZE 26

// Compare function
int compFunc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

bool closeStrings(char* word1, char* word2) {
    // Compare length of words
    int length = strlen(word1);
    if (length != strlen(word2))
        return false;
    // alph for counting number of each alphabet
    // check for collecting basis set of words
    int check1[ALP_SIZE] = { 0 }, check2[ALP_SIZE] = { 0 };
    int alph1[ALP_SIZE] = { 0 }, alph2[ALP_SIZE] = { 0 };

    // set check & count alph
    for (int i = 0; i < length; i++) {
        check1[word1[i] - 'a'] = 1;
        alph1[word1[i] - 'a']++;
    }
    for (int i = 0; i < length; i++) {
        check2[word2[i] - 'a'] = 1;
        alph2[word2[i] - 'a']++;
    }

    // check difference of basis
    for (int i = 0; i < ALP_SIZE; i++) {
        if (check1[i] != check2[i])
            return false;
    }

    // sort & check the alphs
    qsort(alph1, ALP_SIZE, sizeof(int), compFunc);
    qsort(alph2, ALP_SIZE, sizeof(int), compFunc);
    for (int i = 0; i < ALP_SIZE; i++) {
        if (alph1[i] != alph2[i])
            return false;
    }

    return true;
}