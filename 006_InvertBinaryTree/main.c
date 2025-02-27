/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TNode;

typedef struct TemplateNode {
    struct TreeNode* treeNode;
    struct TemplateNode* previous;
    struct TemplateNode* next;
} Node;

struct MyStack {
    size_t size;
    Node* tail;
};

struct MyQueue {
    size_t size;
    Node* head;
    Node* tail;
};

typedef struct MyStack Stack;
typedef struct MyQueue Queue;

static Stack* InitStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->size = 0;
    newStack->tail = NULL;
    return newStack;
}

static Queue* InitQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->size = 0;
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
}

void push(Stack* s, TNode* newTNode) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->treeNode = newTNode;
    if (s->size == 0) {
        newNode->previous = NULL;
        s->tail = newNode;
    }
    else {
        newNode->previous = s->tail;
        s->tail = newNode;
    }
    s->size += 1;
}

void Qpush(Queue* s, TNode* newTNode) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->treeNode = newTNode;
    newNode->next = NULL;
    if (s->size == 0) {
        s->head = newNode;
        s->tail = s->head;
    }
    else {
        s->tail->next = newNode;
        s->tail = newNode;
    }
    s->size += 1;
}

void pop(Stack* s) {
    Node *temp = NULL;
    if (s->tail->previous != NULL) {
        temp = s->tail;
        s->tail = temp->previous;
    }
    else {
        temp = s->tail;
        s->tail = NULL;
    }
    free(temp);
    s->size -= 1;
}

void Qpop(Queue* s) {
    Node *temp = NULL;
    if (s->head->next != NULL) {
        temp = s->head;
        s->head = temp->next;
    }
    else { //end
        temp = s->head;
        s->head = NULL;
        s->tail = NULL;
    }
    free(temp);
    s->size -= 1;
}

static TNode* top(Stack* s) {
    return s->tail->treeNode;
}

static TNode* Qtop(Queue* s) {
    return s->head->treeNode;
}

static void Traverse(Stack* myStack, TNode* tNode) {
    if (tNode != NULL) {
        push(myStack, tNode->right);
        push(myStack, tNode->left);
        Traverse(myStack, tNode->right);
        Traverse(myStack, tNode->left);
        tNode->right = top(myStack);
        pop(myStack);
        tNode->left = top(myStack);
        pop(myStack);
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    // Stack* myStack = InitStack();
    // Traverse(myStack, root);
    // return root;

    //I release that we really need the stack to store the nodes, just swap it :)
    if (root != NULL) {
        invertTree(root->right);
        invertTree(root->left); 
        //after go to the leaf and come back, we swap the node
        struct TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
    return root; //this will be NULL, it will right or left of the leaf
}

TNode* ConstructTreeFromArray(int* a, size_t idx, size_t size) {
    //With a full binary tree, a node at (i) index will have left node at (2*(i)+1) index and right node at (2*(i)+2) index
    //Therefore, a tree will have at max ((size-1)/2) internal nodes and ((size+1)/2) leaves
    //this can only work with full binary tree
    int val = 0;
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->val = a[idx];
    val = a[idx];
    if (idx < (size-1)/2) { //this will be a node, dix start from 0 to (number of nodes - 1)
        newNode->left = ConstructTreeFromArray(a, 2*idx+1, size);
        newNode->right = ConstructTreeFromArray(a, 2*idx+2, size);
    }
    else { //this will be a leaf
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void printTree(TNode* root) {
    size_t size = 0;
    Queue* myQueue = InitQueue();
    //
    Qpush(myQueue, root);
    size = myQueue->size;
    while (size != 0) {
        TNode* node = Qtop(myQueue);
        Qpop(myQueue);
        printf("%d ", node->val);
        if (node->left != NULL) Qpush(myQueue, node->left);
        if (node->right != NULL) Qpush(myQueue, node->right);
        size = myQueue->size;
    }

    free(myQueue);
}

void freeTree(TNode* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    int a[]= {4,2,1,3,5,8,9}; 
    TNode* myNode = ConstructTreeFromArray(a, 0, sizeof(a)/sizeof(int));

    printTree(myNode);
    printf("\n");
    TNode* invertMyNode = invertTree(myNode);

    printTree(invertMyNode);
    freeTree(myNode);

    return 0;
}