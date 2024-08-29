/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = INT_MIN;
    int dfs(struct TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left, right);
    }
    dfs(root);
    return maxSum;
}