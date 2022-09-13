/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char compareChar;
    char *returnChar, *newPtr;
    returnChar = (char*)malloc(sizeof(char));
    if (returnChar == NULL) {
            printf("malloc error");
            return NULL;
    }
    // returnChar = newPtr;
    // free(newPtr);
    for (int charIndex = 0; strs[0][charIndex] != '\0'; charIndex++) {
        // take character of the first string as comparing sample
        // printf("%d %c   ", charIndex, compareChar);
        strncpy(&compareChar, &strs[0][charIndex], 1);
        printf("%d %c   ", charIndex, compareChar);
        for (int strIndex = 1; strIndex < strsSize; strIndex++) {
            // compare character of the same position, if any not comparison go to the end
            // printf("%d/%d %c   ", strIndex, charIndex, compareChar);
            // if (compareChar != strs[strIndex][charIndex]) {
                // printf("%d %c\n", charIndex, compareChar);
                // goto end;
            // }
            // printf("%s  \n", returnChar);
        }
        // printf("%d %c   ", charIndex, compareChar);
        // newPtr = realloc(returnChar, ((charIndex + 2) * sizeof(char)));
        // printf("iii%s", newPtr);
        if(newPtr == NULL){
            printf("realloc error\n");
            return NULL;
        }
        returnChar = newPtr;
        // free(newPtr);
        // printf("%ciiii", compareChar);
        strcat(&returnChar[charIndex], &compareChar);
        printf("iii%s", returnChar);
    }
    // end:
    
    return strs[0];
}
// @lc code=end

/*
 * Longest Common Prefix
 * 
 * Write a function to find the longest common prefix 
 * string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Example 2:
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * Constraints:
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 */