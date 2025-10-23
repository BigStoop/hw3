#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
    
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
    }
    else {
        Node* curr = head;
        curr->next = nullptr;
        head = head->next;

        llpivot(head, smaller, larger, pivot);


        if(curr->val >= pivot) {
            curr->next = larger;
            larger = curr;
        }
        else {
            curr->next = smaller;
            smaller = curr;
        }
    }

}