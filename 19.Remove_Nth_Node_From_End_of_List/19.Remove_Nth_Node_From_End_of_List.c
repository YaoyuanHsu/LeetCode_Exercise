// Way 1
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

// Way 2
/*
typedef struct ListNode ListNode;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int firstCheck = 1, index = 1;
    ListNode *tmp = head, *preN = head, *last = NULL;

    // Find the distance with input number
    for (; tmp->next ; index++)
        tmp = tmp->next;

    // If ther has only one node
    if(index == 1){
        free(head);
        return NULL;
    }

    // Find the last N_th node and the last N+1_th node
    for(int count = 0 ; count < index - n ; count++){
        last = preN;
        preN = preN->next;
    }

    // Checking if we want to remove the head
    if(index - n){
        last->next = preN->next;
        free(preN);
    }
    else
        head = head->next;

    return head;
}
*/