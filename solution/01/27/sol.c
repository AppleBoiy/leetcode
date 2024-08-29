int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int* visited = (int*)calloc(wordListSize, sizeof(int));
    int queueSize = wordListSize + 1;
    int* queue = (int*)malloc(queueSize * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = -1;
    int moves = 1;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            int current = queue[front++];
            if (current != -1 && strcmp(wordList[current], endWord) == 0) {
                free(visited);
                free(queue);
                return moves;
            }
            for (int j = 0; j < wordListSize; j++) {
                if (visited[j]) {
                    continue;
                }
                int diff = 0;
                for (int k = 0; wordList[j][k]; k++) {
                    if (wordList[j][k] != (current == -1 ? beginWord[k] : wordList[current][k])) {
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
    return 0;
}