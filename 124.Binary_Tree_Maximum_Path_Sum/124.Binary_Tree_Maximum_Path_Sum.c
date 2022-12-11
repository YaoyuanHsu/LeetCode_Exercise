/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TNODE;
#define CASE_MIN -1001
#define MAX(x, y) ((x) > (y) ? (x) : (y))

// Find the depth from root to leaf
int DEPTH_MAX_SEARCH(TNODE* root, int* crossMax) {
    // If node is null, return CASE_MIN
    if (!root)
        return CASE_MIN;
    int left = DEPTH_MAX_SEARCH(root->left, crossMax);
    int right = DEPTH_MAX_SEARCH(root->right, crossMax);
    // No-child leaf return its value
    if (left == CASE_MIN && right == CASE_MIN)
        return root->val;
    int maxChild = MAX(left, right);
    // Avoid child having CASE_MIN, using maxChild as filter
    *crossMax = MAX(*crossMax, maxChild);
    *crossMax = MAX(*crossMax, root->val);
    *crossMax = MAX(*crossMax, (left + right + root->val));
    return MAX((maxChild + root->val), root->val);
}

int maxPathSum(struct TreeNode* root) {
    int crossMax = CASE_MIN;
    int depthMax = DEPTH_MAX_SEARCH(root, &crossMax);
    return MAX(crossMax, depthMax);
}