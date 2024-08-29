#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* node = obj->root;
    int index;
    for (int i = 0; word[i] != '\0'; i++) {
        index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* node = obj->root;
    int index;
    for (int i = 0; word[i] != '\0'; i++) {
        index = word[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return node != NULL && node->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* node = obj->root;
    int index;
    for (int i = 0; prefix[i] != '\0'; i++) {
        index = prefix[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    return true;
}

void trieFreeNode(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            trieFreeNode(node->children[i]);
        }
    }
    free(node);
}

void trieFree(Trie* obj) {
    if (obj == NULL) return;
    trieFreeNode(obj->root);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */