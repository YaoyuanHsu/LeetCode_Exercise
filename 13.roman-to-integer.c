/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

// @lc code=start
/*
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 */

int romanToInt(char* s) {
    int ans = 0, length = strlen(s);
    int* strArray = calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        switch (s[i]) {
            case 'I':
                strArray[i] = 1;
                break;

            case 'V':
                strArray[i] = 5;
                break;

            case 'X':
                strArray[i] = 10;
                break;

            case 'L':
                strArray[i] = 50;
                break;

            case 'C':
                strArray[i] = 100;
                break;

            case 'D':
                strArray[i] = 500;
                break;

            case 'M':
                strArray[i] = 1000;
                break;

            default:
                printf("Error input!\n");
                break;
        }
    }

    for (int i = 0; i < length; i++) {
        if (i != length - 1 && strArray[i] < strArray[i + 1]) {
            ans += strArray[i + 1] - strArray[i++];
        } else {
            ans += strArray[i];
        }
    }
    return ans;
}
// @lc code=end
