/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int listSize = 0;
    ListNode *tmp, *preN, *last;

    tmp = head;

    for (int i = 0; i < n; i++)
        tmp = tmp->next;

    preN = head;
    last = NULL;

    for (; tmp->next != NULL;) {
        tmp = tmp->next;
        last = preN;
        preN = preN->next;
    }

    if (last == head)
        return last->next;

    last = preN;
    preN = preN->next;

    last->next = preN->next;
    return head;
}
// @lc code=end

/**
 * @brief Given the head of a linked list, remove the n^th node from the end of
 * the list and return its head.

 * Example 1:
 *  Input: head = [1,2,3,4,5], n = 2
 *  Output: [1,2,3,5]

 * Example 2:
 *  Input: head = [1], n = 1
 *  Output: []

 * Example 3:
 *  Input: head = [1,2], n = 1
 *  Output: [1]

 * Constraints:
 *  The number of nodes in the list is sz.
 *  1 <= sz <= 30
 *  0 <= Node.val <= 100
 *  1 <= n <= sz
 */