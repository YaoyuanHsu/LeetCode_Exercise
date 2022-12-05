/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *fast, *slow;
    for (fast = head, slow = head;;) {
        // Wether we can jump to the next node
        if (fast->next != NULL) {
            // Whether we can jump two nodes?If we can, jump and set slow
            // pointer
            if ((fast->next)->next != NULL) {
                fast = (fast->next)->next;
                slow = slow->next;
            }
            // If we can only jump ome node, it means the link-list has even
            // nodes and slow is the first middle
            else
                return slow->next;
        }
        // If we can not jump to the next node, it means we have odd nodes and
        // slow is the middle
        else
            return slow;
    }
}