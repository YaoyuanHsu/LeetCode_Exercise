/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    // Sequentially checking each digit is carry or not
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i] = digits[i] + carry;
        if (digits[i] == 10) {
            digits[i] = 0;
            carry = 1;
            continue;
        }
        carry = 0;
        break;
    }
    // Using carry bit to assign correst return size
    *returnSize = digitsSize + carry;
    int* ans = malloc(*returnSize * sizeof(int));
    // Assign number from digits with shifting of digits by carry
    for (int i = *returnSize - 1; i > 0; i--)
        ans[i] = digits[i - carry];
    ans[0] = carry ? 1 : digits[0];
    return ans;
}