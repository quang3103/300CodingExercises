#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define open_1      '('
#define close_1     ')'
#define open_2      '{'
#define close_2     '}'
#define open_3      '['
#define close_3     ']'

struct MyNode {
    char c;
    struct MyNode* previous;
};

typedef struct MyNode Node;

struct MyStack {
    size_t size;
    Node* tail;
};

typedef struct MyStack Stack;

Stack* InitStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->size = 0;
    newStack->tail = NULL;
    return newStack;
}

void push(Stack* s, char c) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->c = c;
    if (s->size == 0) {
        newNode->previous = NULL;
        s->tail = newNode;
    }
    newNode->previous = s->tail;
    s->tail = newNode;
    s->size += 1;
}

void pop(Stack* s) {
    if (s->tail->previous != NULL) {
        Node *temp = s->tail;
        s->tail = temp->previous;
        free(temp);
        s->size -= 1;
    }
}

char top(Stack* s) {
    return s->tail->c;
}

bool isEmpty(Stack* s) {
    return (s->size == 0);
}

bool isValid(char* s) {
    size_t i=0,len=strlen(s);
    char c;

    Stack* myStack = InitStack();

    for (i=0; i<len; i++) {
        if ((s[i] == open_1) || (s[i] == open_2) || (s[i] == open_3)) {
            push(myStack, s[i]);
        }
        else {
            if (isEmpty(myStack)) {
                free(myStack);
                return false;
            }
            c = myStack->tail->c;
            if ((s[i] == close_1) && (c != open_1)) {
                free(myStack);
                return false;
            }
            if ((s[i] == close_2) && (c != open_2)) {
                free(myStack);
                return false;
            }
            if ((s[i] == close_3) && (c != open_3)) {
                free(myStack);
                return false;
            }
            pop(myStack);
        }
    }
    if (!isEmpty(myStack)) {
        free(myStack);
        return false;
    }
    free(myStack);
    return true;
}
char a[] = "]]";

int main() {
    printf("is valid: %d\n", isValid(a));
}