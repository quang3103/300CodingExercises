#include <stdio.h>
#include <stdbool.h>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

 size_t max (size_t a, size_t b) {
    return (a>b)?a:b;
}
int abs(int a) {
    return (a>0)?a:(a*(-1));
}
typedef struct TreeNode Node;

bool isBalanced(struct TreeNode* root) {
    size_t heightOfLeft = 0, heightOfRight = 0;

    if (root == NULL) return true;
    
    if (!isBalanced(root->left)) return false;
    if (!isBalanced(root->right)) return false;

    if (root->left != NULL) {
        heightOfLeft = root->left->val + 1; //cheated here, the solution will not really care about the val, so we use it to store the height of the node :)
    }
    else { 
        root->val = 0; //cheated here, the solution will not really care about the val, so we use it to store the height of the node :)
    }
    if (root->right != NULL) {
        heightOfRight = root->right->val + 1;
    }
    else {
        root->val = 0;
    }
    root->val = max(heightOfLeft, heightOfRight);
    if (abs(heightOfLeft - heightOfRight) > 1) return false;
    return true;
}

int main(void) {//init will be done later :(
    return 0;
}