class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> queens(n, -1);
        backtrack(result, queens, 0);
        return result;
    }

    void backtrack(int& result, vector<int>& queens, int row) {
        if (row == queens.size()) {
            result++;
            return;
        }

        for (int i = 0; i < queens.size(); i++) {
            if (isValid(queens, row, i)) {
                queens[row] = i;
                backtrack(result, queens, row + 1);
                queens[row] = -1;
            }
        }
    }

    bool isValid(vector<int>& queens, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || abs(row - i) == abs(col - queens[i])) {
                return false;
            }
        }
        return true;
    }
};