#include <stdio.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int max(int a, int b) {
    return a>b?a:b;
}

typedef struct TreeNode Node;

int maxDepth(struct TreeNode* root) {
    if (root != NULL)
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    return 0;
}

int main(void) {
    return 0;
}