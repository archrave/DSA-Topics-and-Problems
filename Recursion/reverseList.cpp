#include<iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* h = NULL;
// ListNode* reverse(ListNode* head)
// {
//     if(head == NULL)
//     {
//         return 
//     }
//     else{
//         return reverse(head->next);
//     }
// }
void printBackwards(ListNode* head)
{
    if(head == NULL)
    {
        return;
    }
    else{

        printBackwards(head->next);
        cout<<head->val<<" ";
    }
}

void traverse(ListNode* h){
    while (h != NULL)
    {
        cout<< h->val<<" ";
        h=h->next;
    }
    return;
}

int main(){
    ListNode* head = new ListNode;
    head -> val = 5;
    ListNode* temp = head;
    temp -> next = new ListNode;
    temp = temp -> next;
    temp -> val = 4;
    temp -> next = new ListNode;
    temp = temp -> next;
    temp -> val = 3;
    temp -> next = new ListNode;
    temp = temp -> next;
    temp -> val = 2;
    temp -> next = new ListNode;
    temp = temp -> next;
    temp -> val = 1;
    temp -> next = NULL;
    traverse(head);
    cout<<endl;
    printBackwards(head);
    return 0;
}