typedef struct ListNode LINODE;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    LINODE ans, *tmp = &ans;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tmp->next = list1;
            list1 = list1->next;
        } else {
            tmp->next = list2;
            list2 = list2->next;
        }
        tmp = tmp->next;
    }
    tmp->next = list1 ? list1 : list2;
    return ans.next;
}