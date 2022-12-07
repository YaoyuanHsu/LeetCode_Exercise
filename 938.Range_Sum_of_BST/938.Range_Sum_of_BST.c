// Type 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (!root)
        return 0;
    return (((root->val >= low) && (root->val <= high)) ? root->val : 0) +
        ((root->right) ? rangeSumBST(root->right, low, high) : 0) +
        ((root->left) ? rangeSumBST(root->left, low, high) : 0);
}

// Type 2

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (!root)
        return 0;
    if (root->right) {
        if (root->left) {
            return (((root->val >= low) && (root->val <= high)) ? root->val : 0) +
                rangeSumBST(root->right, low, high) +
                rangeSumBST(root->left, low, high);
        }
        return (((root->val >= low) && (root->val <= high)) ? root->val : 0) +
            rangeSumBST(root->right, low, high);
    }
    if (root->left) {
        return (((root->val >= low) && (root->val <= high)) ? root->val : 0) +
            rangeSumBST(root->left, low, high);
    }
    return (((root->val >= low) && (root->val <= high)) ? root->val : 0);
}

// Type 3

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (!root)
        return 0;
    int result = 0;
    result += ((root->val >= low) && (root->val <= high)) ? root->val : 0;
    if (root->left)
        result += rangeSumBST(root->left, low, high);
    if (root->right)
        result += rangeSumBST(root->right, low, high);
    return result;
}