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
    if (firstCheck == 1) {
        tmp = head->next;
        free(head);
        return tmp;
    }

    // After we find pointers of the number we wanted and the previous number,
    // reconnect the linked list
    tmp = preN;
    last->next = preN->next;
    free(tmp);
    return head;
}