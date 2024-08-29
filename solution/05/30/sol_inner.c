/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root) {
    int minDiff = INT_MAX;
    int prev = -1;
    void inorder(struct TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        if (prev != -1) {
            minDiff = fmin(minDiff, root->val - prev);
        }
        prev = root->val;
        inorder(root->right);
    }
    inorder(root);
    return minDiff;
}