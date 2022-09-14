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
    int listSize;
    int remainTarget;
    struct node *back;
} NODE;

// create node with remain target value
void newNode(int remainTarget, int now, NODE* reNode, NODE* back){
    reNode->remainTarget = remainTarget;
    reNode->listSize = back ? back->listSize + 1 : 0;
    reNode->now = now;
    reNode->back = back;
}

// expanded list and add new number
void addList(int* list, int num){
    int listSize = sizeof(list)/sizeof(int);
    int *ptr = realloc(list, (++listSize) * sizeof(int));
    if(!ptr){
        printf("realloc error\n");
        return ;
    }
    list = ptr;
    *(list + listSize) = num;
}

// use deep first search to find corresponding set
int* DFS(int* candidates, NODE* remain, int** list, int* returnSize, int** returnColumnSizes, int preNum){
    printf("preNum: %d\n", preNum);
    // not success
    if (remain->now == 1 && *(candidates + remain->now) > remain->remainTarget)
        return (int*)0;

    // not fail select correct candidate
    while(*candidates + remain->now - 1 > remain->remainTarget){
        if(remain->now == 1)    //not success
            return NULL;
        remain->now--;
    }

    // recursive
    remain->remainTarget -= *(candidates + remain->now - 1);
    int* ptr = DFS(candidates, remain, list, returnSize, returnColumnSizes, *(candidates + remain->now - 1));
    if(ptr){
        if(preNum != 0){   // not root, add previous number and return
            addList(ptr, preNum);
        }
        else{   // if it is root, we find the answer
            *returnSize++;
            int** nptr = realloc(returnColumnSizes, sizeof(returnColumnSizes) + sizeof(int**));
            if(!nptr){
                printf("realloc error\n");
                return (int*)0;
            }
            returnColumnSizes = nptr;
            *(*returnColumnSizes + sizeof(*returnColumnSizes) / sizeof(int*) - 1) = sizeof(ptr) / sizeof(int) + 1;
        }
        return ptr;
    }
    return (int*)0;
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
    NODE* root;
    int **list;
    root = (NODE*)malloc(sizeof(NODE));
    newNode(target, candidatesSize, root, (int*)0);
    DFS(candidates, root, list, returnSize, returnColumnSizes, 0);
    return list;
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