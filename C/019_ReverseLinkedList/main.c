#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode* reverseList(struct ListNode* head) {
    Node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    next = NULL;

    while (curr != NULL) {
        //store the next
        next = curr->next;
        
        //revert the next
        curr->next = prev;

        //interate to next
        prev = curr; 
        curr = next; //when curr is NULL, so prev is the new head 
    }
    return prev;
}

int main(void) {

    printf("test\n");
    return 0;
}