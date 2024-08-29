int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    int n = boardSize;
    int* visited = (int*)calloc(n * n, sizeof(int));
    int* queue = (int*)malloc(n * n * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = 0;
    visited[0] = 1;
    int moves = 0;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            int current = queue[front++];
            if (current == n * n - 1) {
                return moves;
            }
            for (int j = 1; j <= 6 && current + j < n * n; j++) {
                int next = current + j;
                int row = n - 1 - next / n;
                int col = (n - 1 - row) % 2 == 0 ? next % n : n - 1 - next % n;
                if (board[row][col] != -1) {
                    next = board[row][col] - 1;
                }
                if (!visited[next]) {
                    visited[next] = 1;
                    queue[rear++] = next;
                }
            }
        }
        moves++;
    }

    return -1;
}