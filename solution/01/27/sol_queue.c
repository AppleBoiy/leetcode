struct queue {
    int front, rear;
    int capacity;
    int *array;
};

struct queue *createQueue(int capacity) {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->array = (int *)malloc(capacity * sizeof(int));
    return q;
}

void enqueue(struct queue *q, int data) {
    q->array[q->rear++] = data;
}

int dequeue(struct queue *q) {
    return q->array[q->front++];
}

int isEmpty(struct queue *q) {
    return q->front == q->rear;
}

void freeQueue(struct queue *q) {
    free(q->array);
    free(q);
}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int* visited = (int*)calloc(wordListSize, sizeof(int));
    int queueSize = wordListSize + 1;
    struct queue *q = createQueue(queueSize);
    enqueue(q, -1);
    int moves = 1;

    while (!isEmpty(q)) {
        int levelSize = q->rear - q->front;
        for (int i = 0; i < levelSize; i++) {
            int current = dequeue(q);
            if (current != -1 && strcmp(wordList[current], endWord) == 0) {
                free(visited);
                freeQueue(q);
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
                    enqueue(q, j);
                }
            }
        }
        moves++;
    }

    free(visited);
    freeQueue(q);
    return 0;
}