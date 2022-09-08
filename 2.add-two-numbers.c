/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list
 */
// struct ListNode {
//         int val;
//         struct ListNode *next;
// }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int carry = 0;
        struct ListNode *current, *ans;
        ans = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = ans;
        while (l1 != NULL || l2 != NULL || carry != 0) {
                carry = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry) / 10;
                current->val = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry) % 10;
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
                current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        }
        current->next = NULL;
        free(current);
        return ans;
}
// @lc code=end