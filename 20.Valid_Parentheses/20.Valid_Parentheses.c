bool isValid(char* s) {
    int strLen = 0;
    int *brackCount, *tmp;
    strLen = strlen(s);
    brackCount = calloc(strLen, sizeof(int));
    tmp = brackCount;
    for (int i = 0; i < strLen; i++) {
        switch (s[i]) {
            // Left brackets
            case '(':
                *(tmp++) = 1;
                break;
            case '[':
                *(tmp++) = 2;
                break;
            case '{':
                *(tmp++) = 3;
                break;
            // Right brackets
            case ')':
                // # of left > # of right
                if (tmp == brackCount)
                    return false;
                // Not match
                if (*--tmp != 1)
                    return false;
                break;
            case ']':
                if (tmp == brackCount)
                    return false;
                if (*--tmp != 2)
                    return false;
                break;
            case '}':
                if (tmp == brackCount)
                    return false;
                if (*--tmp != 3)
                    return false;
                break;
            // Not brackets
            default:
                return false;
        }
    }
    // # of right > # of left
    if (tmp != brackCount)
        return false;

    return true;
}