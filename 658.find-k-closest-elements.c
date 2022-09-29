/*
 * @lc app=leetcode id=658 lang=c
 *
 * [658] Find K Closest Elements
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* arrAssign(int* arr, int* retArr, int* returnSize) {
    retArr = calloc(*returnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++)
        retArr[i] = arr[i];
    return retArr;
}

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int* retArr;
    // If array size is 1, return whole array
    if ((arrSize == 1)||(arrSize==k)) {
        *returnSize = arrSize;
        return arrAssign(arr, retArr, returnSize);
    }

    int first, last;
    first = arr[0] - x;
    *returnSize = k;
    last = arr[arrSize - 1] - x;

    // If both of them are positive or negative
    if (first >= 0 && last >= 0)
        return arrAssign(arr, retArr, returnSize);
    if (first <= 0 && last <= 0)
        return arrAssign(arr + arrSize - k, retArr, returnSize);

    // Find the first number that cross positive, negative and zero
    int i = 0;
    while ((arr[i] - x) * (arr[i + 1] - x) > 0)
        i++;

    // printf("i:%d\n", i);

    // Set the checking range base
    if ((arr[i + 1] - x) == 0) {
        k--;
        first = i;
        last = i + 2;
    } else if ((arr[i] - x) == 0) {
        k--;
        first = i - 1;
        last = i + 1;
    } else {
        first = i;
        last = i + 1;
    }
    // printf("first:%d, last:%d, k:%d\n", first, last, k);

    for (; k > 0; k--) {
        // printf("first:%d, last:%d, k:%d\n", first, last, k);

        // If we get the first number but number is not enough, the return array
        // starting from the head of array
        if (first < 0)
            return arrAssign(arr, retArr, returnSize);

        // If we had got the last number but number is still not enough
        if (arrSize - last < 1) {
            first--;
            k--;
            // printf("first:%d, last:%d, k:%d\n", first, last, k);
            break;
        }

        // If the gap of the first number is smaller
        if (abs(arr[first] - x) <= abs(arr[last] - x))
            first--;
        // If the gap of the last number is smaller
        else
            last++;
    }
    // printf("%d\n", first);
    return arrAssign(arr + first + 1, retArr, returnSize);
}
// @lc code=end

//[1,2]\n1\n1
//[1,2,3,4,5]\n4\n3
//[1,2,5,5,6,6,7,7,8,9]\n7\n7
//[0,1,2,2,2,3,6,8,8,9]\n5\n9

/**
 * @brief Given a sorted integer array arr, two integers k and x, return the k
 * closest integers to x in the array. The result should also be sorted in
 * ascending order. An integer a is closer to x than an integer b if:
 *  |a - x| < |b - x|, or
 *  |a - x| == |b - x| and a < b

 * Example 1:
 *  Input: arr = [1,2,3,4,5], k = 4, x = 3
 *  Output: [1,2,3,4]

 * Example 2:
 *  Input: arr = [1,2,3,4,5], k = 4, x = -1
 *  Output: [1,2,3,4]

 * Constraints:
 *  1 <= k <= arr.length
 *  1 <= arr.length <= 10^4
 *  arr is sorted in ascending order.
 *  -10^4 <= arr[i], x <= 10^4
 */