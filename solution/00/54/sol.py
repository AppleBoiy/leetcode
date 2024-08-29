from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:  # noqa
        if not matrix:
            return []
        res = []
        while matrix:
            res += matrix.pop(0)
            matrix = list(zip(*matrix))[::-1]
        return res


if __name__ == '__main__':
    _matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    _expected = [1, 2, 3, 6, 9, 8, 7, 4, 5]

    _solution = Solution()
    _result = _solution.spiralOrder(_matrix)
    assert _result == _expected, f"{_result=}, {_expected=}"
