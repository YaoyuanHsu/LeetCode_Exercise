/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <limits.h>

int reverse(int x) {
    int* check = malloc(sizeof(int));
    int negative = (x < 0), first = x % 10, remain = x / 10, res = 0;
    while (remain != 0) {
        // if input is negative number
        if (negative && INT_MIN / 10 <= res) {
            res *= 10;
            if (INT_MIN - first <= res)
                res += first;
            else
                return 0;
        }

        // if input is positive number
        else if (!negative && INT_MAX / 10 >= res) {
            res *= 10;
            if (INT_MAX - first >= res)
                res += first;
            else
                return 0;
        } else
            return 0;
        first = remain % 10;
        remain = remain / 10;
    }

    if (first != 0) {
        // if input is negative number
        if (negative && INT_MIN / 10 <= res) {
            res *= 10;
            if (INT_MIN - first <= res)
                return res += first;
        }

        // if input is positive number
        else if (!negative && INT_MAX / 10 >= res) {
            res *= 10;
            if (INT_MAX - first >= res)
                return res += first;
        } else
            return 0;
    }

    return res;
}
// @lc code=end
// 1463847412
/**
 * @brief Given a signed 32-bit integer x, return x with its digits reversed.
 * If reversing x causes the value to go outside the signed 32-bit integer
 * range [-2^31, 2^31 - 1], then return 0.

 * Assume the environment does not allow you to store 64-bit
 * integers (signed or unsigned).

 * Example 1:
 *  Input: x = 123
 *  Output: 321

 * Example 2:
 *  Input: x = -123
 *  Output: -321

 * Example 3:
 *  Input: x = 120
 *  Output: 21

 * Constraints:
 *  -2^31 <= x <= 2^31 - 1
 */