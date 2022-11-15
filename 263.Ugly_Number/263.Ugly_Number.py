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
        # tmp = divideBy(n, 2)
        # if tmp == 1:
        #     return True
        # tmp = divideBy(tmp, 3)
        # if tmp == 1:
        #     return True
        # tmp = divideBy(tmp, 5)
        # if tmp == 1:
        #     return  True
        # return False

        return divideBy(divideBy(divideBy(n, 2), 3), 5) == 1