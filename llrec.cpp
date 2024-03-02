#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    //base case - if list empty, initialize to NULL
    if (head == NULL) {
        smaller = NULL;
        larger = NULL;
        return;
    }

    //recursive step
    Node *next = head->next;
    head->next = NULL;
    llpivot(next, smaller, larger, pivot);

    if (head->val <= pivot) {
        head->next = smaller;
        smaller = head;
    } else {
        head->next = larger;
        larger = head;
    }
   head = NULL;
}
