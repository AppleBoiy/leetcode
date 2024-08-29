class Solution:
    def convert(self, s: str, num_rows: int) -> str:  # noqa
        if num_rows == 1:
            return s

        rows = [''] * min(num_rows, len(s))
        going_down = False
        cur_row = 0

        for c in s:
            rows[cur_row] += c
            if cur_row == 0 or cur_row == num_rows - 1:
                going_down = not going_down
            cur_row += 1 if going_down else -1

        return ''.join(rows)


if __name__ == '__main__':
    _s = "PAYPALISHIRING"
    _num_rows = 3
    _expected = "PAHNAPLSIIGYIR"

    solution = Solution()
    output = solution.convert(_s, _num_rows)
    assert output == _expected, f"{output} != {_expected}"
