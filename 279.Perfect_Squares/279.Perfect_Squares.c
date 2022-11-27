#define MIN(x, y) x < y ? x : y

int numSquares(int n) {
    int* result = malloc((n + 1) * sizeof(int));
    int sqrt_bound = 0;
    for (int num = 0; num <= n; num++) {
        result[num] = num;
        sqrt_bound = sqrt(num);
        for (int remain_sqrt = 1; remain_sqrt <= sqrt_bound; remain_sqrt++)
            result[num] =
                MIN(result[num], result[num - remain_sqrt * remain_sqrt] + 1);
    }

    return result[n];
}