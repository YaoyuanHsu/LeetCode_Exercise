/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TNODE;
int postOrder(TNODE* root, int max, int min) {
    if (!root)
        return max - min;
    max = (root->val > max) ? root->val : max;
    min = (root->val < min) ? root->val : min;
    int left = postOrder(root->left, max, min);
    int right = postOrder(root->right, max, min);
    return left > right ? left : right;
}

int maxAncestorDiff(struct TreeNode* root) {
    if (!root)
        return 0;
    return postOrder(root, root->val, root->val);
}