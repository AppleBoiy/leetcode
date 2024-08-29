from typing import List


class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:  # noqa
        """
        Do not return anything, modify board in-place instead.
        """
        rows, cols = len(board), len(board[0])
        for i in range(rows):
            for j in range(cols):
                count = 0
                for x in range(max(0, i - 1), min(rows, i + 2)):
                    for y in range(max(0, j - 1), min(cols, j + 2)):
                        count += board[x][y] & 1
                if count == 3 or count - board[i][j] == 3:
                    board[i][j] |= 2
        for i in range(rows):
            for j in range(cols):
                board[i][j] >>= 1
