ListNode* detectCycle(ListNode* head) {
    ListNode* s = head, * f = head;

    do {
        if (!f || !f->next) {
            return NULL;
        }
        s = s->next;
        f = f->next->next;

    } while (s != f);

    f = head;
    while (s != f) {
        f = f->next;
        s = s->next;
    }
    return s;
}