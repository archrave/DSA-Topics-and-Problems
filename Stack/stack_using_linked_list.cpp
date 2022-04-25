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

class Stack
{

    Node *head;
    int length;

public:
    Stack()
    {
        head = NULL;
        length = 0;
    }

    void push(int data)
    {
        if (!head)
        {
            head = new Node(data);
            head->next = NULL;
            length++;
            return;
        }
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        length++;
    }
    void pop()
    {
        if (!head)
        {
            cout << "\nStack Underflow!\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        length--;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int size()
    {
        return length;
    }

    int top()
    {
        if (!head)
        {
            cout << "\nStack Empty!\n";
            return 0;
        }
        return head->data;
    }

    void print()
    {
        Node *temp = head;
        cout << "\nStack: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    Stack s1;
    int choice;
    while (true)
    {
        cout << "\n\n****** Stack ********\n\n";
        cout << "1. push()\n2. pop()\n3. print()\n4. size()\n5. isEmpty()\n6. top()\n7. exit()\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "\nEnter data: ";
            cin >> data;
            s1.push(data);
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.print();
            break;
        case 4:
            cout << "\nSize: " << s1.size() << endl;
            break;
        case 5:
            if (s1.isEmpty())
                cout << "\nStack is Empty!";
            else
                cout << "Stack is not Empty!";
            break;
        case 6:
            cout << "\nTop of Stack: " << s1.top() << endl;
            break;
        case 7:
            return 0;
            break;
        default:
            cout << "\nInvalid Input!\n";
            break;
        }
    }
    return 0;
}