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