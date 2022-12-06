/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode LISTNODE;

struct ListNode* oddEvenList(struct ListNode* head) {
    // Under three node just return list
    if ((!head) || (!head->next) || (!head->next->next))
        return head;
    // Initialize pointers
    LISTNODE *lastOdd = head, *firstEven = lastOdd->next,
             *lastEven = lastOdd->next;
    // Run until find the last odd node or the last even node
    while (lastEven && lastEven->next) {
        // Find the next odd node
        lastOdd = lastOdd->next = lastEven->next;
        // Add even node to even-list
        lastEven = lastEven->next = lastOdd->next;
    }
    // Concate the odd list and even  list
    lastOdd->next = firstEven;
    return head;
}