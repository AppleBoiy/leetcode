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
} WordDictionary;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node) {
        int i;
        node->isEndOfWord = false;
        for (i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

bool searchHelper(TrieNode* node, char* word);

WordDictionary* wordDictionaryCreate() {
    WordDictionary* wordDictionary = (WordDictionary*)malloc(sizeof(WordDictionary));
    if (wordDictionary) {
        wordDictionary->root = createNode();
    }
    return wordDictionary;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    TrieNode* node = obj->root;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index]) {
            node->children[index] = createNode();
        }
        node = node->children[index];
        word++;
    }
    node->isEndOfWord = true;
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return searchHelper(obj->root, word);
}

bool searchHelper(TrieNode* node, char* word) {
    if (*word == '\0') {
        return node->isEndOfWord;
    }

    if (*word == '.') {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i] && searchHelper(node->children[i], word + 1)) {
                return true;
            }
        }
        return false;
    } else {
        int index = *word - 'a';
        if (node->children[index]) {
            return searchHelper(node->children[index], word + 1);
        } else {
            return false;
        }
    }
}

void wordDictionaryFree(WordDictionary* obj) {
    freeTrie(obj->root);
    free(obj);
}

void freeTrie(TrieNode* node) {
    if (!node) {
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            freeTrie(node->children[i]);
        }
    }
    free(node);
}