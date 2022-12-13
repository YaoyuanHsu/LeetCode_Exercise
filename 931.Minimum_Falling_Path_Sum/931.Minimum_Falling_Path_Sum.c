int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize) {
    int** localMin = (int**)malloc(matrixSize * sizeof(int*));
    int left, mid, right, min, row, col;
    for (int i = 0; i < matrixSize; i++)
        localMin[i] = (int*)malloc(sizeof(int) * matrixSize);
    for (row = 0; row < matrixSize; row++) {
        for (col = 0; col < matrixSize; col++) {
            if (row == 0) {
                localMin[row][col] = matrix[row][col];
                continue;
            }
            left = (col - 1 < 0) ? INT_MAX : localMin[row - 1][col - 1];
            mid = localMin[row - 1][col];
            right =
                (col + 1 >= matrixSize) ? INT_MAX : localMin[row - 1][col + 1];
            min = (left < mid) ? left : mid;
            min = (min < right) ? min : right;
            localMin[row][col] = matrix[row][col] + min;
        }
    }
    for (row = matrixSize - 1, col = 0, min = INT_MAX; col < matrixSize; col++)
        min = (min < localMin[row][col]) ? min : localMin[row][col];
    return min;
}