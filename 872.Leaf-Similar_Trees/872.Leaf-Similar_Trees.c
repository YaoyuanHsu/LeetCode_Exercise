/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode* TNODE;
typedef struct leafString {
    int val;
    struct leafString* next;
} LSTR;

void leafChecker(TNODE root, LSTR** lstr) {
    if (!root->left && !root->right) {
        // Create new node
        LSTR* newNode = (LSTR*)malloc(sizeof(LSTR));
        newNode->val = root->val;
        newNode->next = NULL;
        // Get the pointer of the last node
        LSTR *pre = NULL, *tmp = *lstr;
        while (tmp != NULL) {
            pre = tmp;
            tmp = tmp->next;
        }
        // Append new node
        if (pre)
            pre->next = newNode;
        else
            *lstr = newNode;
        return;
    }
    // If child of tree is not null
    if (root->left)
        leafChecker(root->left, lstr);
    if (root->right)
        leafChecker(root->right, lstr);
    return;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    // If only one tree is empty, return false
    if ((!root1 && root2) || (root1 && !root2))
        return false;
    LSTR *lstr1 = NULL, *lstr2 = NULL;
    // In-order DFS search
    // Using address of pointer for null pointer assignment
    leafChecker(root1, &lstr1);
    leafChecker(root2, &lstr2);
    // Comparing leaf list
    while (lstr1 && lstr2) {
        if (lstr1->val != lstr2->val)
            return false;
        lstr1 = lstr1->next;
        lstr2 = lstr2->next;
    }
    if (lstr1 || lstr2)
        return false;
    return true;
}