#include <stdio.h>
#include <stdlib.h>
//
//struct Node {
//    int val;
//    struct Node* left;
//    struct Node* right;
//    struct Node* next;
//};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* curr = root;
    struct Node* dummy = createNode(0);
    struct Node* prev = dummy;

    while (curr != NULL) {
        while (curr != NULL) {
            if (curr->left != NULL) {
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right != NULL) {
                prev->next = curr->right;
                prev = prev->next;
            }
            curr = curr->next;
        }
        curr = dummy->next;
        dummy->next = NULL;
        prev = dummy;
    }

    free(dummy);
    return root;
}

