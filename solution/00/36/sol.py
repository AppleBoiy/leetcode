from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:  # noqa
        is_valid: callable = lambda nums: len(set(nums)) == len(nums)

        for row in board:
            if not is_valid([cell for cell in row if cell != "."]):
                return False

        for col in range(9):
            if not is_valid([board[row][col] for row in range(9) if board[row][col] != "."]):
                return False

        for row in range(0, 9, 3):
            for col in range(0, 9, 3):
                if not is_valid(
                        [
                            board[r][c]
                            for r in range(row, row + 3)
                            for c in range(col, col + 3)
                            if board[r][c] != "."
                        ]
                ):
                    return False

        return True


if __name__ == '__main__':
    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    expected = True

    solution = Solution()
    result = solution.isValidSudoku(board)
    assert result == expected, f"{result=}, {expected=}"
