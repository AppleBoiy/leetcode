#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
    int size;
};

void enqueue(struct Queue *queue, struct TreeNode *node) {
    struct QueueNode *newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

struct TreeNode* dequeue(struct Queue *queue) {
    if (queue->size == 0) {
        return NULL;
    }
    struct TreeNode *node = queue->front->node;
    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return node;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct Queue queue = {NULL, NULL, 0};
    enqueue(&queue, root);

    int maxLevels = 100;
    int **result = (int **)malloc(maxLevels * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxLevels * sizeof(int));

    int level = 0;

    while (queue.size > 0) {
        if (level >= maxLevels) {
            maxLevels *= 2;
            result = (int **)realloc(result, maxLevels * sizeof(int *));
            *returnColumnSizes = (int *)realloc(*returnColumnSizes, maxLevels * sizeof(int));
        }

        int levelSize = queue.size;
        (*returnColumnSizes)[level] = levelSize;
        result[level] = (int *)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *current = dequeue(&queue);
            result[level][i] = current->val;
            if (current->left != NULL) {
                enqueue(&queue, current->left);
            }
            if (current->right != NULL) {
                enqueue(&queue, current->right);
            }
        }
        level++;
    }

    *returnSize = level;
    return result;
}