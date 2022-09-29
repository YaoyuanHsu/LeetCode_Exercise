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
    int firstCheck = 1;
    ListNode *tmp = head, *preN = head, *last = NULL;

    // Find the distance with input number
    for (int i = 1; i < n; i++)
        tmp = tmp->next;

    // Move the whole set to the end
    for (; tmp->next != NULL ;) {
        tmp = tmp->next;
        last = preN;
        preN = preN->next;
        firstCheck = 0;
    }

    // If we wamt to remove the first number, we have to use NULL pointer.
    // Define a first number checker for checking
    if(firstCheck == 1)
        return head->next;

    // After we find pointers of the number we wanted and the previous number,
    // reconnect the linked list
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