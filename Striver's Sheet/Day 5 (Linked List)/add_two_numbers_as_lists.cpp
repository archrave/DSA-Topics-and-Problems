ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* t1 = l1, * t2 = l2, * prev = t1, * prev2 = t2;
    int carry = 0;
    while (t1 && t2) {
        prev = t1;
        prev2 = t2;
        int sum = t1->val + t2->val + carry;
        if (sum >= 10) {
            carry = 1;
            t1->val = sum % 10;
        }
        else {
            carry = 0;
            t1->val = sum;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    if (!t1 && !t2 && carry == 1)
    {
        prev->next = prev2;
        prev2->val = carry;
        carry = 0;
    }
    while (t1) {
        prev = t1;
        t1->val += carry;
        if (t1->val >= 10) {
            t1->val %= 10;
            carry = 1;
        }
        else {
            carry = 0;
            break;
        }

        t1 = t1->next;
    }
    if (t2) {
        prev->next = t2;
    }
    while (t2) {
        prev = t2;
        t2->val += carry;
        if (t2->val >= 10) {
            t2->val %= 10;
            carry = 1;
        }
        else {
            carry = 0;
            break;
        }
        t2 = t2->next;
    }
    if (carry == 1) {
        // cout<<"prev: "<<prev->val<<endl;  
        prev->next = new ListNode(1);
    }
    return l1;

}