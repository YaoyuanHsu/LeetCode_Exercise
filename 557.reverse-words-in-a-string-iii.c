/*
 * @lc app=leetcode id=557 lang=c
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
// @lc code=end

/**
 * @brief Given a string s, reverse the order of characters in each word within
 * a sentence while still preserving whitespace and initial word order.

 * Example 1:
 *  Input: s = "Let's take LeetCode contest"
 *  Output: "s'teL ekat edoCteeL tsetnoc"

 * Example 2:
 *  Input: s = "God Ding"
 *  Output: "doG gniD"

 * Constraints:
 *  1 <= s.length <= 5 * 10^4
 *  s contains printable ASCII characters.
 *  s does not contain any leading or trailing spaces.
 *  There is at least one word in s.
 *  All the words in s are separated by a single space.
 */