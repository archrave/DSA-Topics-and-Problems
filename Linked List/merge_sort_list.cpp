#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void printList(Node *h)
{
    while (h != NULL)
    {
        cout << h->data << " ";
        h = h->next;
    }
    cout << endl;
}
void addAtStart(Node **h, int data)
{
    Node *newNode = new Node(data);
    // newNode->data = data;
    newNode->next = (*h);
    (*h) = newNode;
}

Node *findMid(Node *head)
{
    Node *fast = head->next, *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    Node *head = NULL, *tail = NULL;
    if (list1->data < list2->data)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        list2 = list2->next;
    }
    tail = head;
    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    if (list1)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }
    return head;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = findMid(head), *mid = NULL, *l1 = NULL, *l2 = NULL;
    mid = prev->next;
    prev->next = NULL;
    l1 = mergeSort(head);
    l2 = mergeSort(mid);
    return mergeTwoLists(l1, l2);
}
int main()
{
    Node *head = NULL;
    addAtStart(&head, 10);
    addAtStart(&head, 2);
    addAtStart(&head, 1);
    addAtStart(&head, 4);
    addAtStart(&head, 7);
    addAtStart(&head, 6);
    addAtStart(&head, 8);
    addAtStart(&head, 3);
    addAtStart(&head, 5);
    addAtStart(&head, 9);
    printList(head);
    head = mergeSort(head);
    printList(head);
    return 0;
}