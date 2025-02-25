/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

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

int main() {

}