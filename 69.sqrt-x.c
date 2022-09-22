/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start

int mySqrt(int x) {
    int pre = x / 2, now = x / 4;
    if (x == 1)
        return 1;
    // 4 is the largest number that (num^2)/4 <= num
    if (x <= 4)
        return x / 2;
    while (1) {
        // if search window cross the answer, the upper range is the answer
        if (x / pre >= pre)
            return pre;
        // using binary search concept to find the range that sqrt exist
        if (x / now < now || (x / now == now && x % now)) {
            pre = now;
            now /= 2;
        }
        // if we find the range search form both ended
        else {
            pre--;
            now++;
        }
    }
}
// @lc code=end

/**
 * @brief Given a non-negative integer x, compute and return the square root of
 * x. Since the return type is an integer, the decimal digits are truncated, and
 * only the integer part of the nowult is returned.
 *
 * Note: You are not allowed to use any built-in exponent function or operator,
 * such as pow(x, 0.5) or x ** 0.5.
 *
 * Example 1:
 * Input: x = 4
 * Output: 2
 *
 * Example 2:
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since the decimal part
 * is truncated, 2 is returned.
 *
 * Constraints:
 * 0 <= x <= 2^31 - 1
 *
 */