int climbStairs(int n) {
    if (n < 3)
        return n;
    int preOne = 0, preTwo = 1, result = 2;
    for (int i = 2; i < n; i++) {
        preOne = preTwo;
        preTwo = result;
        result = preOne + preTwo;
    }
    return result;
}