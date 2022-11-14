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