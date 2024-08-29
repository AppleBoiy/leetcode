#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct HashMapEntry {
    struct Node* original;
    struct Node* clone;
    struct HashMapEntry* next;
};

struct HashMap {
    struct HashMapEntry** table;
    int size;
};

struct Node* createNode(int val, int numNeighbors) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->numNeighbors = numNeighbors;
    newNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * numNeighbors);
    return newNode;
}

struct HashMap* createHashMap(int size) {
    struct HashMap* map = (struct HashMap*)malloc(sizeof(struct HashMap));
    map->table = (struct HashMapEntry**)malloc(sizeof(struct HashMapEntry*) * size);
    map->size = size;
    for (int i = 0; i < size; ++i) {
        map->table[i] = NULL;
    }
    return map;
}

int hash(struct Node* node, int size) {
    return ((uintptr_t)node) % size;
}

struct Node* findClone(struct HashMap* map, struct Node* node) {
    int index = hash(node, map->size);
    struct HashMapEntry* entry = map->table[index];
    while (entry) {
        if (entry->original == node) {
            return entry->clone;
        }
        entry = entry->next;
    }
    return NULL;
}

void insertClone(struct HashMap* map, struct Node* original, struct Node* clone) {
    int index = hash(original, map->size);
    struct HashMapEntry* entry = (struct HashMapEntry*)malloc(sizeof(struct HashMapEntry));
    entry->original = original;
    entry->clone = clone;
    entry->next = map->table[index];
    map->table[index] = entry;
}

struct Node* dfsClone(struct Node* node, struct HashMap* map) {
    if (!node) return NULL;

    struct Node* clonedNode = findClone(map, node);
    if (clonedNode) {
        return clonedNode;
    }

    clonedNode = createNode(node->val, node->numNeighbors);
    insertClone(map, node, clonedNode);

    for (int i = 0; i < node->numNeighbors; ++i) {
        clonedNode->neighbors[i] = dfsClone(node->neighbors[i], map);
    }

    return clonedNode;
}

struct Node *cloneGraph(struct Node *s) {
    if (!s) return NULL;

    struct HashMap* map = createHashMap(1024);
    struct Node* clonedGraph = dfsClone(s, map);

    for (int i = 0; i < map->size; ++i) {
        struct HashMapEntry* entry = map->table[i];
        while (entry) {
            struct HashMapEntry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(map->table);
    free(map);

    return clonedGraph;
}