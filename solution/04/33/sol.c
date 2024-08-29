#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    int* visited = (int*)calloc(bankSize, sizeof(int));
    int queueSize = bankSize + 1;
    int* queue = (int*)malloc(queueSize * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = -1;
    int moves = 0;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            int current = queue[front++];
            if (current != -1 && strcmp(bank[current], endGene) == 0) {
                free(visited);
                free(queue);
                return moves;
            }
            for (int j = 0; j < bankSize; j++) {
                if (visited[j]) {
                    continue;
                }
                int diff = 0;
                for (int k = 0; bank[j][k]; k++) {
                    if (bank[j][k] != (current == -1 ? startGene[k] : bank[current][k])) {
                        if (++diff > 1) {
                            break;
                        }
                    }
                }
                if (diff == 1) {
                    visited[j] = 1;
                    queue[rear++] = j;
                }
            }
        }
        moves++;
    }

    free(visited);
    free(queue);
    return -1;
}