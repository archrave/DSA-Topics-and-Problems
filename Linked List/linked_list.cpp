#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

void printList(ListNode *h)
{
    while (h != NULL)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}

int lengthOfList(ListNode *h)
{
    int count = 0;
    while (h != NULL)
    {
        count++;
        h = h->next;
    }
    return count;
}

void addAtStart(ListNode **h, int data)
{
    ListNode *newNode = new ListNode();
    newNode->data = data;
    newNode->next = (*h);
    (*h) = newNode;
}

void addAtLast(ListNode **h, int data)
{
    ListNode *temp = (*h), *newNode = new ListNode();
    newNode->data = data;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = NULL;
    temp->next = newNode;
}

void addAtPosition(ListNode **h, int data, int pos)
{
    int length = lengthOfList(*h);
    if (pos < 1 || pos > length + 1)
    {
        cout << "Position argument is out of range!" << endl;
        return;
    }
    else if (pos == 1)
    {
        addAtStart(h, data);
    }
    else if (pos == length + 1)
    {
        addAtLast(h, data);
    }
    else
    {
        ListNode *temp = (*h);
        ListNode *newNode = new ListNode();
        newNode->data = data;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtStart(ListNode **h)
{
    ListNode *temp = (*h);
    (*h) = (*h)->next;
    delete temp;
}

void deleteAtLast(ListNode **h)
{
    ListNode *p = (*h), *q = NULL;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    delete p;
}

void deleteAtPosition(ListNode **h, int pos)
{
    int length = lengthOfList(*h);
    if (pos < 1 || pos > length)
    {
        cout << "Position argument is out of range!" << endl;
        return;
    }
    else if (pos == 1)
    {
        deleteAtStart(h);
    }
    else if (pos == length)
    {
        deleteAtLast(h);
    }
    else
    {
        ListNode *q = (*h), *p = (*h);

        for (int i = 1; i < pos; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        p->next = NULL;
        delete p;
    }
}

int main()
{
    ListNode *head = NULL;
    addAtStart(&head, 1);
    addAtStart(&head, 2);
    addAtStart(&head, 3);
    addAtStart(&head, 4);
    addAtStart(&head, 5);
    addAtLast(&head, 10);
    addAtPosition(&head, 200, 6);
    printList(head);
    deleteAtPosition(&head, 0);
    printList(head);
    deleteAtPosition(&head, 8);
    printList(head);
    deleteAtPosition(&head, 1);
    printList(head);
    deleteAtPosition(&head, 6);
    printList(head);
    deleteAtPosition(&head, 3);
    printList(head);
    return 0;
}