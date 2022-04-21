#include <iostream>
using namespace std;
// Node Structure:
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

void addAtLast(Node **h, int data)
{
    Node *temp = (*h), *newNode = new Node(data);
    // newNode->data = data;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = NULL;
    temp->next = newNode;
}

int length(Node *h)
{
    int count = 0;
    while (h != NULL)
    {
        count++;
        h = h->next;
    }
    return count;
}
void deleteAtPos(Node **h, int pos)
{
    Node *temp = (*h), *prev = (*h);
    if ((*h) == NULL)
    {
        cout << "\nEmpty List!\n";
        return;
    }
    if (pos > length(*h) || pos < 1)
    {
        cout << "\nInvalid position!\n";
        return;
    }
    else if (pos == 1)
    {
        (*h) = (*h)->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    for (int i = 1; i < pos - 1; i++)
    {
        prev = prev->next;
    }
    temp = prev->next;
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

void deleteithNodeFromEnd(Node **head, int k)
{
    Node *slow = *head, *fast = *head, *temp = NULL;
    for (int i = 1; i <= k; i++)
    {
        fast = fast->next;
    }
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    temp = slow->next;
    slow->next = temp->next;
    temp->next = NULL;
    delete temp;
}

Node *reverseList(Node *head)
{
    Node *temp = head, *prev = NULL;
    while (head != NULL)
    {
        head = head->next;
        temp->next = prev;
        prev = temp;
        temp = head;
    }
    return prev;
}

int main()
{
    Node *head = NULL;
    addAtStart(&head, 1);
    addAtStart(&head, 2);
    addAtStart(&head, 3);
    addAtStart(&head, 4);
    addAtStart(&head, 5);
    addAtLast(&head, 10);
    printList(head);
    cout << "Length: " << length(head) << endl
         << endl;
    deleteithNodeFromEnd(&head, 3);
    printList(head);
    cout << "Length: " << length(head) << endl;
    return 0;
}