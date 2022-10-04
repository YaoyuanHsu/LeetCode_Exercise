/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

// @lc code=start
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
// @lc code=end

/**
 * @brief Given a string s containing just the characters '(', ')', '{', '}','['
 * and ']', determine if the input string is valid.
 * An input string is valid if:
 *  1.Open brackets must be closed by the same type of brackets.
 *  2.Open brackets must be closed in the correct order.
 *  3.Every close bracket has a corresponding open bracket of the same type.

 * Example 1:
 *  Input: s = "()"
 *  Output: true

 * Example 2:
 *  Input: s = "()[]{}"
 *  Output: true

 * Example 3:
 *  Input: s = "(]"
 *  Output: false

 * Constraints:
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 */