class Solution {
    func dfs(_ board: inout [[Character]], _ i: Int, _ j: Int) {
        if i < 0 || i >= board.count || j < 0 || j >= board[i].count || board[i][j] != "O" {
            return
        }
        board[i][j] = "1"
        dfs(&board, i + 1, j)
        dfs(&board, i - 1, j)
        dfs(&board, i, j + 1)
        dfs(&board, i, j - 1)
    }

    func solve(_ board: inout [[Character]]) {
        let m = board.count
        let n = board[0].count
        for i in 0..<m {
            for j in 0..<n {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == "O" {
                    dfs(&board, i, j)
                }
            }
        }
        for i in 0..<m {
            for j in 0..<n {
                if board[i][j] == "O" {
                    board[i][j] = "X"
                } else if board[i][j] == "1" {
                    board[i][j] = "O"
                }
            }
        }
    }
}