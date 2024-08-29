#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX_NODES 10000

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    double* averages = (double*)malloc(MAX_NODES * sizeof(double));
    *returnSize = 0;
    struct TreeNode* queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        double sum = 0.0;

        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = queue[front++];

            sum += node->val;
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        averages[(*returnSize)++] = sum / levelSize;
    }

    return averages;
}