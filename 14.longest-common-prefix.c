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
    returnChar = (char*)malloc(sizeof(char));   //size of char and size of char pointer is different
    // if (returnChar == NULL) {
    //     printf("malloc error");
    //     return NULL;
    // }
    // initialize memory for empty prefix return
    memset(returnChar, '\0', sizeof(char));
    for (int charIndex = 0; strs[0][charIndex] != '\0'; charIndex++) {
        // take character of the first string as comparing sample
        strncpy(&compareChar, &strs[0][charIndex], 1);
        for (int strIndex = 1; strIndex < strsSize; strIndex++) {
            // compare character of the same position, if any not comparison go to the end
            if (compareChar != strs[strIndex][charIndex]) {
                goto end;
            }
        }
        // allocate 2 new memory space for new prefix and '\0'
        returnChar = realloc(returnChar, ((charIndex + 2) * sizeof(char)));
        // if(newPtr == NULL){
        //     printf("realloc error\n");
        //     return NULL;
        // }
        // returnChar = newPtr;
        strncpy(returnChar + charIndex, &compareChar, 1);
        strncpy(returnChar + charIndex + 1, "\0", 1);
    }
    end:
    
    return returnChar;
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