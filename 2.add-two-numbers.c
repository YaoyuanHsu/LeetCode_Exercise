/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (39.43%)
 * Likes:    21243
 * Dislikes: 4182
 * Total Accepted:    3.1M
 * Total Submissions: 7.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Example 2:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Example 3:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 * Constraints:
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    int carry = 0;
    struct ListNode *tmp, *ans, *last;
    ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp = ans;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        tmp->val =
            ((l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry) %
            10;
        carry =
            ((l1 != NULL ? l1->val : 0) + (l2 != NULL ? l2->val : 0) + carry) /
            10;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
        last = tmp;
        tmp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp = tmp->next;
    }
    last->next = NULL;
    return ans;
}
// @lc code=end