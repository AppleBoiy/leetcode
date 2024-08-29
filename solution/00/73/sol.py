from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:  # noqa
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = len(matrix), len(matrix[0])
        zero_rows, zero_cols = set(), set()
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    zero_rows.add(i)
                    zero_cols.add(j)
        for i in range(rows):
            for j in range(cols):
                if i in zero_rows or j in zero_cols:
                    matrix[i][j] = 0


if __name__ == '__main__':
    _matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    _expected = [[1, 0, 1], [0, 0, 0], [1, 0, 1]]

    solution = Solution()
    solution.setZeroes(_matrix)
    assert _matrix == _expected, f"{_matrix} != {_expected}"
