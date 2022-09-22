/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(int* returnList, struct TreeNode* root, int* returnSize) {
    if (root == NULL)
        return 0;
    inorder(returnList, root->left, returnSize);
    returnList[(*returnSize)++] = root->val;
    inorder(returnList, root->right, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* returnList = malloc(100 * sizeof(int));
    inorder(returnList, root, returnSize);
    return returnList;
}
// @lc code=end

/**
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 * Example 1:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 * Example 2:
 * Input: root = []
 * Output: []
 *
 * Example 3:
 * Input: root = [1]
 * Output: [1]
 *
 * Constraints:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */