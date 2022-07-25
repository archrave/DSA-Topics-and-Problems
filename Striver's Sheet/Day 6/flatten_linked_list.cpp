#include <bits/stdc++.h> 

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

// ****************************************************************

void print(Node* head) {
    cout << endl;
    while (head) {
        cout << head->data << "->";
        head = head->child;
    }
    cout << endl;
}

Node* mergeTwoLists(Node* a, Node* b) {

    Node* temp = new Node(0);
    Node* res = temp;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }

    if (a) temp->child = a;
    else temp->child = b;

    return res->child;

}
Node* flatten(Node* head)
{

    if (head == NULL || head->next == NULL)
        return head;

    // recur for list on right 
    head->next = flatten(head->next);

    // now merge 
    head = mergeTwoLists(head, head->next);

    // return the head 
    // it will be in turn merged with its left 
    return head;
}
int main() {

}