#include <stdlib.h>
#include <stdbool.h>

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

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
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

    bool leftToRight = true;
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

        struct TreeNode* nodes[levelSize];
        for (int i = 0; i < levelSize; i++) {
            nodes[i] = dequeue(&queue);
        }

        if (leftToRight) {
            for (int i = 0; i < levelSize; i++) {
                result[level][i] = nodes[i]->val;
            }
        } else {
            for (int i = 0; i < levelSize; i++) {
                result[level][i] = nodes[levelSize - 1 - i]->val;
            }
        }

        for (int i = 0; i < levelSize; i++) {
            if (nodes[i]->left != NULL) {
                enqueue(&queue, nodes[i]->left);
            }
            if (nodes[i]->right != NULL) {
                enqueue(&queue, nodes[i]->right);
            }
        }

        leftToRight = !leftToRight;
        level++;
    }

    *returnSize = level;
    return result;
}