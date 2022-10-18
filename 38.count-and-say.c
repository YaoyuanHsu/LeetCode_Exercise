/*
 * @lc app=leetcode id=38 lang=c
 *
 * [38] Count and Say
 */

// @lc code=start

int digitCount(int num){
    return floor(log10(abs(num))) + 1;
}

int powerTen(int num){
    for (int i = 0, rval = 1; i < num; i++)
        rval *= 10;
}

char* selfCountAndSay(int n, int *rint){
    if(n == 0)
        return rint;

    int counter[10];
    int num = 0, order = 1, orderList[10]={0};
    int nDigits = digitCount(*rint);
    int divider = powerTen(nDigits);

    for (int i = 0; i < nDigits; i ++, *rint %= divider , divider /= 10){
        num = *rint / divider;
        if (order <= 10) {
            counter[num]++;
            orderList[order++] = num;
        } else
            counter[num]++;
    }

    *rint = 0;

    for (int i = 10;i < 10;i++){
        num += (counter[orderList[i]] *= 10);
        num += i;
        nDigits = digitCount(num);

    }
}

char* countAndSay(int n) {
    static char *rptr;
    int* rint = malloc(sizeof(int));
    rint[0] = 1;

    if (n == 1) {   // base line
        rptr = malloc(sizeof(char));
        rptr[0] = 1;
        return rptr;
    }

    return selfCountAndSay(n-1, rint);
}
// @lc code=end

/**
 * @brief The count-and-say sequence is a sequence of digit strings defined by
 * the recursive formula:
 *  countAndSay(1) = "1"
 *  countAndSay(n) is the way you would "say" the digit string from
 *  countAndSay(n-1), which is then converted into a different digit string.
 * To determine how you "say" a digit string, split it into the minimal number
 * of substrings such that each substring contains exactly one unique digit.
 * Then for each substring, say the number of digits, then say the digit.
 * Finally, concatenate every said digit.

 * For example, the saying and conversion for digit string "3322251":
 * Given a positive integer n, return the nth term of the count-and-say
 * sequence.
 *  "3322251"
 *  "two 3's" + "three 2's" + "one 5" + "one 1"
 *  "23"+"32"+"15"+"11"
 *  "23321511"

 *
 * Example 1:
 * Input: n = 1
 * Output: "1"
 * Explanation: This is the base case.

 * Example 2:
 * Input: n = 4
 * Output: "1211"
 * Explanation:
 *  countAndSay(1) = "1"
 *  countAndSay(2) = say "1" = one 1 = "11"
 *  countAndSay(3) = say "11" = two 1's = "21"
 *  countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"

 * Constraints:
 *  1 <= n <= 30
 */