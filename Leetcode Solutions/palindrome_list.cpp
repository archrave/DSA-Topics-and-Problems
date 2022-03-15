#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *reverse(ListNode *head)
{
    ListNode *pre = NULL;
    ListNode *temp = NULL;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        temp->next = pre;
        pre = temp;
    }
    return temp;
}

ListNode *findMid(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
void printList(ListNode *h)
{
    cout << endl;
    while (h != NULL)
    {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
}

bool isPalindrome(ListNode *head)
{
    ListNode *mid = findMid(head);
    // printList(mid);
    ListNode *head1 = reverse(mid);
    while (head1 != NULL && head != mid)
    {
        if (head->val != head1->val)
            return false;
        head = head->next;
        head1 = head1->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode;
    ListNode *temp = head;
    temp->val = 1;
    temp->next = new ListNode;
    temp = temp->next;
    temp->val = 2;
    temp->next = new ListNode;
    temp = temp->next;
    temp->val = 2;
    temp->next = new ListNode;
    temp = temp->next;
    temp->val = 1;
    temp->next = NULL;
    temp = head;

    ListNode *mid = findMid(head);
    printList(mid);

    cout << isPalindrome(head);
    cout << endl;
    return 0;
}