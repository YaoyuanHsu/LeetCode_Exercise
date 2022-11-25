char* makeGood(char* s) {
    int length = strlen(s);
    // If input is too short, just return
    if ((length <= 1))
        return s;
// Linear search for bad case and modify it
restart:
    length = strlen(s);
    for (int i = 0; i < length - 1; i++) {
        if ((s[i] == s[i + 1] + 32) || (s[i] == s[i + 1] - 32)) {
            for (; i < length - 2; i++)
                s[i] = s[i + 2];
            s[length - 2] = '\0';
            s = (char*)realloc(s, (length - 1) * sizeof(char));
            goto restart;
        }
    }
    return s;
}