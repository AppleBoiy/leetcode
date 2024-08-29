/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k) {
    int count = 0;
    int result = 0;
    void inorder(struct TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        inorder(root->right);
    }
    inorder(root);
    return result;
}