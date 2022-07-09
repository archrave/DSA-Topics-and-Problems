ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head, * fast = head;
    for (int i = 1; fast != NULL && i <= n; i++)
        fast = fast->next;


    if (!fast) {
        head = head->next;
        slow->next = NULL;
        delete slow;
        return head;
    }

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* temp = slow->next;
    slow->next = temp->next;
    temp->next = NULL;
    delete temp;

    return head;
}