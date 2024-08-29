/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            struct TreeNode* rightmost = curr->left;
            while (rightmost->right != NULL) {
                rightmost = rightmost->right;
            }
            rightmost->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}