#define MAX(x, y) (((x) > (y)) ? (x) : (y))
int longestCommonSubsequence(char* text1, char* text2) {
    int length1 = strlen(text1), length2 = strlen(text2);
    int** lcs = malloc((length1 + 1) * sizeof(int*));
    for (int i = 0; i <= length1; i++)
        lcs[i] = calloc((length2 + 1), sizeof(int));

    for (int row = 1; row <= length1; row++) {
        for (int col = 1; col <= length2; col++) {
            if (text1[row - 1] == text2[col - 1])
                lcs[row][col] = lcs[row - 1][col - 1] + 1;
            else
                lcs[row][col] = MAX(lcs[row - 1][col], lcs[row][col - 1]);
        }
    }
    return lcs[length1][length2];
};