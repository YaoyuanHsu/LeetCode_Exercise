int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    int i, j, count = 0, set = numsSize / 2;
    int* returnArray;
    *returnSize = 0;            // initial size
    for (i = 0; i < set; i++)   // count decompress size
        *returnSize += nums[2 * i];
    // memory allocation decompression space
    returnArray = (int*)malloc(*returnSize * sizeof(int));
    for (i = 0; i < set; i++)         // double loop for value assign
        for (j = 0; j < nums[2 * i]; j++, count++)
            returnArray[count] = nums[2 * i + 1];
    return returnArray;
}