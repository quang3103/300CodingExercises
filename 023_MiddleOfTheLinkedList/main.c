#include <stdio.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head) {
    Node *slow = head;
    Node *fast = head;

    while ((fast != NULL) && (fast->next != NULL)) { 
        slow = slow->next;
        fast = fast->next->next; //when fast ends at NULL, slow will be at the middle
    }
    return slow;
}

int main(void) {
    return 0;
}