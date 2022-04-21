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
    if (h == NULL)
    {
        return 0;
    }
    return length(h->next) + 1;
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

Node *findMid(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL || fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverseList(Node *head)
{
    Node *temp = head, *prev = NULL;
}
int main()
{
    Node *head = NULL;
    addAtStart(&head, 1);
    // addAtStart(&head, 2);
    // addAtStart(&head, 3);
    // addAtStart(&head, 4);
    // addAtStart(&head, 5);
    // addAtLast(&head, 10);
    printList(head);
    cout << "Length: " << length(head) << endl;
    // TO FIND MID:

    // cout << "Mid list: ";
    // Node *mid = findMid(head);
    // printList(mid);

    cout << "\n Reversed List: ";
    printList(reverseList(head));
    return 0;
}