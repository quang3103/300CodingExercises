#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ArrayNode {
    int val;
    struct ArrayNode *ptr;
};

typedef struct ArrayNode ArrNode;
typedef struct TreeNode TNode;

int max(int a, int b) {
    return a>b?a:b;
}

int result = 0;

int DFS(struct TreeNode* root) {
    int leftHeight = 0;
    int rightHeight = 0;
    if (root != NULL) {
        leftHeight = DFS(root->left);
        rightHeight = DFS(root->right);
        result = max(result, leftHeight+rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
    return 0;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    result = 0; //reset result because multiple testcases will be run at once...
    DFS(root);
    return result;
}

TNode* ConstructTreeFromArray(ArrNode* a, int idx, size_t size) {

    int leftNodeIdx = idx*2 + 1;
    int rightNodeIdx = idx*2 + 2;

    TNode* newNode = (TNode*)malloc(sizeof(TNode));
    newNode->val = a[idx].val;

    if (leftNodeIdx < size) {
        if (a[leftNodeIdx].ptr != NULL) {
            newNode->left = ConstructTreeFromArray(a, leftNodeIdx, size);
        }
        else { //incomplete tree -> this chill is null
            newNode->left = NULL;
        }
    } 
    else { //out of size
        newNode->left = NULL;
    }
    if (rightNodeIdx < size) {
        if (a[rightNodeIdx].ptr != NULL) {
            newNode->right = ConstructTreeFromArray(a, rightNodeIdx, size);
        }
        else { //incomplete tree -> this chill is null
            newNode->right = NULL;
        }
    } //out of size
    else {
        newNode->right = NULL;
    }

    return newNode;    
}


int main(void) {
    int i;
    ArrNode b[3];

    b[0].val = 1;
    b[0].ptr = &(b[0]);
    b[1].val = 0;
    b[1].ptr = NULL;
    b[2].val = 2;
    b[2].ptr = &(b[2]);

    printf("result: %d ", diameterOfBinaryTree(ConstructTreeFromArray(b, 0, sizeof(b)/sizeof(ArrNode))));
}