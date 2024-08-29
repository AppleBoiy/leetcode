from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:  # noqa
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n):
            for j in range(i, n):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]
        for row in matrix:
            row.reverse()


if __name__ == '__main__':
    _matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    _expected = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

    solution = Solution()
    solution.rotate(_matrix)
    assert _matrix == _expected, f"{_matrix} != {_expected}"
