#
# @lc app=leetcode id=263 lang=python
#
# [263] Ugly Number
#

# @lc code=start
from operator import truediv

def divideBy(n, div):
    while n%div == 0:
        n = n/div
        if n == 1:
            return 1
    return n

class Solution(object):
    def isUgly(self, n):
        if n <= 0:
            return False
        tmp = divideBy(n, 2)
        if tmp == 1:
            return True
        tmp = divideBy(tmp, 3)
        if tmp == 1:
            return True
        tmp = divideBy(tmp, 5)
        if tmp == 1:
            return  True
        return False

        # return divideBy(divideBy(divideBy(n, 2), 3), 5) == 1

# @lc code=end

'''
    An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
    Given an integer n, return true if n is an ugly number.
    Example 1:
        Input: n = 6
        Output: true
        Explanation: 6 = 2 × 3

    Example 2:
        Input: n = 1
        Output: true
        Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5. 

    Example 3:
        Input: n = 14
        Output: false
        Explanation: 14 is not ugly since it includes the prime factor 7.

    Constraints:
        -2^31 <= n <= 2^31 - 1
'''