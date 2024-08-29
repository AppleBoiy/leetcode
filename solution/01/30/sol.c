void dfs(char** board, int m, int n, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
        return;
    }
    board[i][j] = 'A';
    dfs(board, m, n, i - 1, j);
    dfs(board, m, n, i + 1, j);
    dfs(board, m, n, i, j - 1);
    dfs(board, m, n, i, j + 1);
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0) {
        return;
    }
    int m = boardSize, n = *boardColSize;
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                dfs(board, m, n, i, j);
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'A') {
                board[i][j] = 'O';
            }
        }
    }
}