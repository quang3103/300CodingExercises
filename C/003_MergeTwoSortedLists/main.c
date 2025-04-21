/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include <stdio.h>
 #include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

typedef struct LinkedList {
    size_t size;
    Node* head;
    Node* tail;
} ll;

ll* createLLFromArray(int* a, size_t size) {
    size_t i=0;
    ll* myLL = (ll*)malloc(sizeof(ll));
    
    for (i=0; i<size; i++) {
        Node* myNode = (Node*)malloc(sizeof(Node));
        myNode->val = a[i];
        myNode->next = NULL;
        if (i == 0) {
            myLL->size = 1;
            myLL->head = myNode;
            myLL->tail = myLL->head;
        }
        else {
            myLL->size += 1;
            myLL->tail->next = myNode;
            myLL->tail = myNode;
        }
    }
    return myLL;
}


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } 
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int a[] = {1, 2, 3, 4};
int b[] = {1, 2, 4, 5};

ll* lla = NULL;
ll* llb = NULL;
Node* result = NULL;

int main() {
    lla = createLLFromArray(a, sizeof(a)/sizeof(int));
    llb = createLLFromArray(b, sizeof(b)/sizeof(int));
    result = mergeTwoLists(lla->head, llb->head);
    
    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    } 

    return 0;
}