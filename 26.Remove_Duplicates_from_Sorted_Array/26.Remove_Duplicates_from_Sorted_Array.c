int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int valiNum = 1, i = 1;
    for (; i < numsSize; i++) {
        if (nums[i] == nums[i - 1])
            continue;
        nums[valiNum] = nums[i];
        valiNum++;
    }
    return valiNum;
}