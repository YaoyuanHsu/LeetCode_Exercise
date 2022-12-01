int checkVowels(char* c) {
    if (*c == 'a')
        return 1;
    if (*c == 'e')
        return 1;
    if (*c == 'i')
        return 1;
    if (*c == 'o')
        return 1;
    if (*c == 'u')
        return 1;

    if (*c == 'A')
        return 1;
    if (*c == 'E')
        return 1;
    if (*c == 'I')
        return 1;
    if (*c == 'O')
        return 1;
    if (*c == 'U')
        return 1;

    return 0;
}

bool halvesAreAlike(char* s) {
    int length = strlen(s), count = 0;
    for (int i = 0; i < length / 2; i++)
        count += checkVowels(s + i);
    for (int i = length / 2; i < length; i++)
        count -= checkVowels(s + i);
    if (!count)
        return true;
    return false;
}