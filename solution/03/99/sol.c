#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct GraphNode {
    char* key;
    struct GraphNode** neighbors;
    double* weights;
    int size;
} GraphNode;

typedef struct HashMap {
    GraphNode** nodes;
    int size;
    int capacity;
} HashMap;

#define HASH_SIZE 100

int hashFunc(const char* key) {
    unsigned long hash = 5381;
    while (*key) {
        hash = ((hash << 5) + hash) + *key++;
    }
    return hash % HASH_SIZE;
}

HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = 0;
    map->capacity = HASH_SIZE;
    map->nodes = (GraphNode**)calloc(HASH_SIZE, sizeof(GraphNode*));
    return map;
}

GraphNode* createGraphNode(char* key) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->key = strdup(key);
    node->size = 0;
    node->neighbors = NULL;
    node->weights = NULL;
    return node;
}

void insertNode(HashMap* map, char* key) {
    int index = hashFunc(key);
    while (map->nodes[index] != NULL && strcmp(map->nodes[index]->key, key) != 0) {
        index = (index + 1) % map->capacity;
    }
    if (map->nodes[index] == NULL) {
        map->nodes[index] = createGraphNode(key);
        map->size++;
    }
}

GraphNode* getNode(HashMap* map, char* key) {
    int index = hashFunc(key);
    while (map->nodes[index] != NULL && strcmp(map->nodes[index]->key, key) != 0) {
        index = (index + 1) % map->capacity;
    }
    return map->nodes[index];
}

void addEdge(HashMap* map, char* start, char* end, double value) {
    GraphNode* startNode = getNode(map, start);
    GraphNode* endNode = getNode(map, end);

    startNode->neighbors = (GraphNode**)realloc(startNode->neighbors, (startNode->size + 1) * sizeof(GraphNode*));
    startNode->weights = (double*)realloc(startNode->weights, (startNode->size + 1) * sizeof(double));

    startNode->neighbors[startNode->size] = endNode;
    startNode->weights[startNode->size] = value;
    startNode->size++;
}

int bfs(GraphNode* start, GraphNode* end, double* result) {
    if (start == end) {
        *result = 1.0;
        return 1;
    }

    typedef struct {
        GraphNode* node;
        double value;
    } QueueNode;

    QueueNode queue[HASH_SIZE];
    int front = 0, rear = 0;
    queue[rear++] = (QueueNode){start, 1.0};

    int visited[HASH_SIZE] = {0};
    visited[hashFunc(start->key)] = 1;

    while (front < rear) {
        QueueNode current = queue[front++];
        for (int i = 0; i < current.node->size; ++i) {
            GraphNode* neighbor = current.node->neighbors[i];
            double newValue = current.value * current.node->weights[i];
            if (neighbor == end) {
                *result = newValue;
                return 1;
            }
            int neighborIdx = hashFunc(neighbor->key);
            if (!visited[neighborIdx]) {
                visited[neighborIdx] = 1;
                queue[rear++] = (QueueNode){neighbor, newValue};
            }
        }
    }
    return 0;
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char*** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    HashMap* map = createHashMap();
    
    for (int i = 0; i < equationsSize; ++i) {
        char* u = equations[i][0];
        char* v = equations[i][1];
        double value = values[i];
        
        insertNode(map, u);
        insertNode(map, v);
        
        addEdge(map, u, v, value);
        addEdge(map, v, u, 1.0 / value);
    }
    
    *returnSize = queriesSize;
    double* results = (double*)malloc(queriesSize * sizeof(double));
    
    for (int i = 0; i < queriesSize; ++i) {
        char* u = queries[i][0];
        char* v = queries[i][1];
        
        GraphNode* startNode = getNode(map, u);
        GraphNode* endNode = getNode(map, v);
        
        if (startNode == NULL || endNode == NULL) {
            results[i] = -1.0;
        } else {
            double result = 1.0;
            if (bfs(startNode, endNode, &result)) {
                results[i] = result;
            } else {
                results[i] = -1.0;
            }
        }
    }

    return results;
}
