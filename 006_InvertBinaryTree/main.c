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

typedef struct StackNode {
    struct TreeNode* treeNode;
    struct StackNode* previous;
} Node;

typedef struct MyStack Stack;

struct MyStack {
    size_t size;
    Node* tail;
};

static Stack* InitStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->size = 0;
    newStack->tail = NULL;
    return newStack;
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

static TNode* top(Stack* s) {
    return s->tail->treeNode;
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
    //Therefore, a tree will have at max (size/2-1) nodes that are not leaf
    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->val = a[idx];
    if (idx >= size/2) { //this will be a leaf
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else {
        //TODO: check for right node exists or not? 2*idx+1 >= size?
        newNode->left = ConstructTreeFromArray(a, 2*idx+1, size);
        newNode->right = ConstructTreeFromArray(a, 2*idx+2, size);
    }
    return newNode;
}

void printNode(TNode* node) {
    if (node->left != NULL) printf("%d ", node->left->val);
    if (node->right != NULL) printf("%d ", node->right->val);
    if (node->left != NULL) printNode(node->left);
    if (node->right != NULL) printNode(node->right);
}

void printTree(TNode* root) {
    
    printf("%d ", root->val);
    printNode(root);
}

void freeTree(TNode* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    int a[]= {4,2,7,1,3,6,9};
    TNode* myNode = ConstructTreeFromArray(a, 0, sizeof(a)/sizeof(int));

    printTree(myNode);
    printf("\n");
    TNode* invertMyNode = invertTree(myNode);

    printTree(invertMyNode);
    freeTree(myNode);

    return 0;
}