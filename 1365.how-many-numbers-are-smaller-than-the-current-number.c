/*
 * @lc app=leetcode id=1365 lang=c
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int* returnNums = calloc(numsSize, sizeof(int));
    int i, count[101] = { 0 }, all[101] = { 0 };
    for (i = 0; i < numsSize; i++)
        count[nums[i]]++;
    all[1] = count[0];
    for (i = 1; i <= 100; i++)
        all[i] = count[i - 1] + all[i - 1];
    for (i = 0; i < numsSize; i++)
        returnNums[i] = all[nums[i]];
    *returnSize = numsSize;
    return returnNums;
}
// @lc code=end

