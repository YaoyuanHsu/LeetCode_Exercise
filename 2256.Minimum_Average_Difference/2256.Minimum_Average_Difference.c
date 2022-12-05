int minimumAverageDifference(int* nums, int numsSize) {
    if (numsSize == 1)
        return 0;
    long* sum = calloc(numsSize, sizeof(long));
    int index = 0, min = INT_MAX, tmp = 0;
    // Collect all summation
    sum[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
        sum[i] = sum[i - 1] + nums[i];
    for (int i = 0; i < numsSize; i++) {
        // Calculate all average difference
        tmp = abs(sum[i] / (i + 1) -
            ((numsSize - i - 1) ? ((sum[numsSize - 1] - sum[i]) / (numsSize - i - 1)) : 0));
        // Update minimum and index
        if (tmp < min) {
            min = tmp;
            index = i;
        }
    }
    return index;
}