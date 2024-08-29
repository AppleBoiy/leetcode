/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* prev, int* minDiff) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, prev, minDiff);
    if (*prev != -1) {
        *minDiff = fmin(*minDiff, root->val - *prev);
    }
    *prev = root->val;
    inorder(root->right, prev, minDiff);
}

int getMinimumDifference(struct TreeNode* root) {
    int minDiff = INT_MAX;
    int prev = -1;
    inorder(root, &prev, &minDiff);
    return minDiff;
}