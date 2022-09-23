/*
 * @lc app=leetcode id=1680 lang=c
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
#include <stdlib.h>

int binLength(int var) {
    unsigned bits;
    for (bits = 0; var != 0; ++bits)
        var >>= 1;
    return bits;
}

int concatenatedBinary(int n) {
    int length = 0, size = 0;
    long int res = 0;
    int* binType = calloc(1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        length = binLength(i);
        binType = realloc(binType, (length + size) * sizeof(int));
        for (int var = i, count = 0; count < length; count++) {
            binType[size + length - 1 - count] = var % 2;
            var /= 2;
        }
        size += length;
    }

    for (int i = 0; i < size; i++) {
        res *= 2;
        res += binType[i];
    }
    return res;
}
// @lc code=end

/**
 * @brief Given an integer n, return the decimal value of the binary string
 *  formed by concatenating the binary representations of 1 to n in order,
 *  modulo 10^9 + 7.

 * Example 1:
 *  Input: n = 1
 *  Output: 1
 *  Explanation: "1" in binary corresponds to the decimal value 1.

 * Example 2:
 *  Input: n = 3
 *  Output: 27
 *  Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
 *  After concatenating them, we have "11011", which corresponds to the decimal
 *  value 27.

 * Example 3:
 *  Input: n = 12
 *  Output: 505379714
 *  Explanation: The concatenation results in
 *  "1101110010111011110001001101010111100".
 *  The decimal value of that is 118505380540.
 *  After modulo 10^9 + 7, the result is 505379714.

 * Constraints:
 *  1 <= n <= 10^5
 */