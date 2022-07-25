ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
        return head;
    }

    int count = 1;
    ListNode* tail = head, * temp = head;

    while (tail->next) {
        tail = tail->next;
        count++;
    }

    tail->next = head;
    if (k % count == 0 || k == 0) {
        tail->next = NULL;
        return head;
    }

    for (int i = 1; i <= count - k % count; i++) {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    return head;
}