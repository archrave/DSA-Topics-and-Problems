ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = NULL;
    ListNode* prev = head;

    while (list1 && list2) {
        ListNode* greater;
        if (list1->val <= list2->val) {
            greater = list1;
            list1 = list1->next;
        }
        else {
            greater = list2;
            list2 = list2->next;
        }
        // This will run once only, when head is null
        if (!head)
            head = greater;
        else
            prev->next = greater;

        prev = greater;
    }

    if (list1) {
        if (!head)
            head = list1;
        else
            prev->next = list1;
    }
    if (list2) {
        if (!head)
            head = list2;
        else
            prev->next = list2;
    }
    return head;
}