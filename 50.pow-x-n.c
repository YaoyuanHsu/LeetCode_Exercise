/*
 * @lc app=leetcode id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start

double myPow(double x, int n) {
    double res;
    // avoid negative n overflow, we divide by 2 first
    int p = n / 2;

    // simple case
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    // positive power or not
    if (n < 0) {
        x = 1 / x;
        res = myPow(x, -p);
        // we can not directly use 1/x, it may loose accuracy
    } else
        res = myPow(x, p);

    // half number of power
    if (n % 2 == 0)
        return res * res;
    return res * res * x;
}
// @lc code=end

/**
 * @brief Implement pow(x, n), which calculates x raised to the power n
 * (i.e., x^n).
 *
 * Example 1:
 *  Input: x = 2.00000, n = 10
 *  Output: 1024.00000
 *
 * Example 2:
 *  Input: x = 2.10000, n = 3
 *  Output: 9.26100
 *
 * Example 3:
 *  Input: x = 2.00000, n = -2
 *  Output: 0.25000
 *  Explanation: 2^(-2) = 1/(2^2) = 1/4 = 0.25
 *
 * Constraints:
 *  -100.0 < x < 100.0
 *  (-2)^31 <= n <= 2^31-1
 *  n is an integer.
 *  (-10)^4 <= x^n <= 10^4
 */