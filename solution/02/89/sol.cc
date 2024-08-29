class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> next(m, vector<int>(n, 0));
        vector<int> dx = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 0, 0, 1, -1, 1, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        cnt += board[x][y];
                    }
                }
                if (board[i][j] == 1) {
                    if (cnt < 2 || cnt > 3) {
                        next[i][j] = 0;
                    } else {
                        next[i][j] = 1;
                    }
                } else {
                    if (cnt == 3) {
                        next[i][j] = 1;
                    } else {
                        next[i][j] = 0;
                    }
                }
            }
        }
        board = next;
    }
};