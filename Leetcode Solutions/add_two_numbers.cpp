#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *l3 = NULL;
    int carry = 0;
    void addAtLast(ListNode **h, int data)
    {
        ListNode *newNode = new ListNode;
        newNode->next = NULL;
        if ((*h) == NULL)
        {
            newNode->val = data;
            (*h) = newNode;
            return;
        }
        ListNode *temp = (*h);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return l3;
        }
        int data = l1->val + l2->val + carry;
        if (data >= 10)
        {
            data = data % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        addAtLast(&l3, data);
        if (l1->next == NULL && (carry != 0))
        {
            addAtLast(&l3, carry);
        }
        return addTwoNumbers(l1->next, l2->next);
    }
};

int main()
{
    Solution s;
    s.return 0;
}