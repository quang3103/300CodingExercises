#include <stdbool.h>
#include <stdio.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

bool hasCycle(struct ListNode *head) {
    Node* slow = head;
    Node *fast = head;
    
    while ((fast != NULL) && (fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main(void) {
    return 0;
}