char* longestCommonPrefix(char** strs, int strsSize) {
    char compareChar;
    char *returnChar, *newPtr;
    // size of char and size of char pointer is different
    returnChar = (char*)malloc(sizeof(char));
    // initialize memory for empty prefix return
    memset(returnChar, '\0', sizeof(char));
    for (int charIndex = 0; strs[0][charIndex] != '\0'; charIndex++) {
        // take character of the first string as comparing sample
        strncpy(&compareChar, &strs[0][charIndex], 1);
        for (int strIndex = 1; strIndex < strsSize; strIndex++) {
            // compare character of the same position, if any not comparison go
            // to the end
            if (compareChar != strs[strIndex][charIndex]) {
                goto end;
            }
        }
        // allocate 2 new memory space for new prefix and '\0'
        returnChar = realloc(returnChar, ((charIndex + 2) * sizeof(char)));
        strncpy(returnChar + charIndex, &compareChar, 1);
        strncpy(returnChar + charIndex + 1, "\0", 1);
    }
end:
    return returnChar;
}