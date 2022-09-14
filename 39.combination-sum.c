/*
 * @lc app=leetcode id=39 lang=c
 *
 * [39] Combination Sum
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct node{
    int now;    // which candidate we last use, not the index of candidate
    int remainTarget;
    struct node *back;
} NODE;

// create node with remain target value
void newNode(int remainTarget, int now, NODE* reNode, NODE* back){
    reNode->remainTarget = remainTarget;
    reNode->now = now;
    reNode->back = back;
}

//use deep first search to find corresponding set
int** DFS(int* candidates, NODE* remain, int** list, int* returnSize, int** returnColumnSizes){
    // store remain condition or not?
    if (*candidates + remain->now - 1 <= remain->remainTarget){ // choose the candidate
        if(remain->remainTarget - (*candidates + remain->now - 1) == 0){ // find the candidate list

        }
        else{   // unfinished and recursive
            NODE* child;
            child = (NODE*)malloc(sizeof(NODE));
            newNode(remain->remainTarget - (*candidates + remain->now - 1), remain->now, );
            DFS(candidates, child, list, returnSize, returnColumnSizes);
        }
    }
    else if (remain->now == 1){ // run out off candidates, this candidate list not success

    }
    else{   // check the next candidate

    }
    return list;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    /**
     * Data types:
     *  candidatesSize : how many candidates we having
     *  candidates : pointer to the first candidate
     *  target : target number
     *  returnSize : how mant array we return
     *  returnColumnSizes : an array store size of each sub-array 
     */
    int** list;
    NODE* root;
    root = (NODE*)malloc(sizeof(NODE));
    newNode(target, candidatesSize, root, NULL);
    return DFS(candidates, root, list, returnSize, returnColumnSizes);
}
// @lc code=end

/** 
 * Given an array of distinct integers candidates and a target integer target, 
 * return a list of all unique combinations of candidates where the chosen numbers sum to target.
 * You may return the combinations in any order.
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * The test cases are generated such that the number of unique combinations 
 * that sum up to target is less than 150 combinations for the given input.
 * 
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * 
 * Example 2:
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * Example 3:
 * Input: candidates = [2], target = 1
 * Output: []
 */