#include <stdio.h> 
#include <stdbool.h>


struct Node {
    int data;
    struct Node* next;
};

typedef struct Node MyNode;

typedef struct { //we cheated because there is no stack from C std lib :(
    MyNode* head;
    MyNode* tail;
    int size;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* tmp = (MyQueue*)malloc(sizeof(MyQueue));
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->size = 0;
    return tmp;
}

void myQueuePush(MyQueue* obj, int x) {
    MyNode* tmp = (MyNode*)malloc(sizeof(MyNode));
    tmp->data = x;
    tmp->next = NULL;

    if (obj->size == 0) {
        obj->head = tmp;
        obj->tail = obj->head;
    }
    else {
        obj->tail->next = tmp;
        obj->tail = tmp;
    }
    obj->size += 1;
}

int myQueuePop(MyQueue* obj) {
    int tmp = obj->head->data;
    MyNode* tmpNode = obj->head;
    obj->head = obj->head->next;
    free(tmpNode);
    obj->size -= 1;
    return tmp;
}

int myQueuePeek(MyQueue* obj) {
    return obj->head->data;
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->size == 0);
}

void myQueueFree(MyQueue* obj) {
    while (obj->size != 0) {
        int tmp = obj->head->data;
        MyNode* tmpNode = obj->head;
        obj->head = obj->head->next;
        free(tmpNode);
        obj->size -= 1;
    }
    free(obj);
}

int main(void){
    printf("tsstt");
    return 0;
}