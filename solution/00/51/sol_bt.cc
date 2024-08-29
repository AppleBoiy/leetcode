#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long ll;

#define VV(T) vector<vector<T>>
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define MOD 1000000007

static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#endif // LEETCODE_SOLUTION_H__


class Solution {
public:
    void backtrack(int row, int n, vector<string>& board, VV(string)& res, vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) continue;

            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 1;
            backtrack(row + 1, n, board, res, cols, diag1, diag2);
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 0;
        }
    }

    VV(string) solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        VV(string) res;
        vector<int> cols(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);
        backtrack(0, n, board, res, cols, diag1, diag2);
        return res;
    }
};