
// O(m + n) time and space  [Hashmap]:
/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode* , int> umap;

    while(headA){
        umap[headA]++;

        headA = headA->next;
    }
     while(headB){
        umap[headB]++;
        if(umap.at(headB) == 2)
            return headB;
        headB = headB->next;
    }
    return NULL;
}
*/

// Linked List cycle method O(1) space:

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* temp = headA, * s = headB, * f = headB;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = headA;
    do {
        if (!f || !f->next) {
            temp->next = NULL;
            return NULL;
        }
        s = s->next;
        f = f->next->next;

    } while (s != f);

    f = headB;
    while (s != f) {
        f = f->next;
        s = s->next;
    }
    temp->next = NULL;
    return s;
}

// V Simple O(m+n):
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* h1 = headA, * h2 = headB;
    // They will be NULL simultaneouly if there's no intersection point
    while (h1 != h2) {
        if (!h2) {
            h2 = headA;
        }
        else {
            h2 = h2->next;
        }

        if (!h1) {
            h1 = headB;
        }
        else {
            h1 = h1->next;
        }
    }

    return h1;
}