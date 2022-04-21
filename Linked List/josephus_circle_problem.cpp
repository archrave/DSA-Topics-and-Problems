#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void addAtStart(Node **h, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if ((*h) == NULL)
    {
        (*h) = newNode;
        newNode->next = newNode;
        return;
    }
    Node *temp = *h;
    newNode->next = (*h);
    if ((*h)->next == (*h))
    {
        temp->next = newNode;
        (*h) = newNode;
        return;
    }
    while (temp->next != (*h))
        temp = temp->next;
    temp->next = newNode;
    (*h) = newNode;
}

void printList(Node *head)
{
    if (!head)
        return;
    // if (head->next == head)
    // {
    //     cout << head->data << endl;
    //     return;
    // }
    Node *temp = head;
    int count = 1;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteCurrentNode(Node **head, Node **ptr)
{
    Node *temp = (*ptr)->next;
    if ((*head) == (*ptr))
    {
        temp = *ptr;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        *head = (*head)->next;
        temp->next = *head;
        (*ptr)->next = NULL;
        delete (*ptr);
        (*ptr) = *head;
        return;
    }
    if (temp == *head)
    {
        swap((*ptr)->data, (*head)->data);
        *head = (*head)->next;
        (*ptr)->next = *head;
        (*head) = *ptr;
        temp->next = NULL;
        delete temp;
    }
    swap((*ptr)->data, temp->data);
    (*ptr)->next = temp->next;
    temp->next = NULL;
    delete temp;
}
int josephus_circle(int n, int m)
{
    Node *list = NULL, *ptr = NULL;
    for (int i = n; i >= 1; i--)
    {
        addAtStart(&list, i);
    }
    ptr = list;
    int count = 0;
    while (list != list->next)
    {
        count++;
        if (count == m)
        {
            deleteCurrentNode(&list, &ptr);
            count++;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return list->data;
}
int main()
{
    Node *head = NULL;
    addAtStart(&head, 4);
    addAtStart(&head, 3);
    addAtStart(&head, 2);
    addAtStart(&head, 1);
    printList(head);
    cout << josephus_circle(4, 2);
    return 0;
}