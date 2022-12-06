char* reverseWords(char* s) {
    int size = 0, length = strlen(s);
    char *token, *res;

    // initialize length +1(for the last '\0') as '\0'
    res = (char*)malloc((length + 1) * sizeof(char));
    memset(res, '\0', length + 1);

    // split string by " "(here can not use ' ')
    token = strtok(s, " ");
    while (token != NULL) {
        // from the position we recorded reverses characters within the length
        // of return token
        for (int i = strlen(token) - 1; i >= 0; size++, i--)
            res[size] = token[i];
        token = strtok(NULL, " ");
        // if there still has data in the string, we assign the last character
        // as space and record plus one
        if (token)
            res[size++] = ' ';
    }
    return res;
}