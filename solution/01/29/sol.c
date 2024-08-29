/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int sum = 0;
    struct TreeNode* curr = root;
    struct TreeNode* prev = NULL;
    struct TreeNode* next = NULL;
    while (curr != NULL) {
        if (curr->left == NULL) {
            sum += curr->val;
            curr = curr->right;
        } else {
            prev = curr->left;
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                sum += curr->val;
                curr = curr->right;
            }
        }
    }
    return sum;
}