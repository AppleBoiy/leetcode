MAX_INT = 2 ** 31 - 1
MIN_INT = - (2 ** 31)


class Solution:
    def reverse(self, _x: int) -> int:  # noqa
        sign = -1 if _x < 0 else 1
        _x = abs(_x)
        reversed_x = int(str(_x)[::-1]) * sign
        if reversed_x < MIN_INT or reversed_x > MAX_INT:
            return 0
        return reversed_x


if __name__ == '__main__':
    x = 123
    expected = 321
    solver = Solution().reverse
    assert (result := solver(x)) == expected, f"unexpected {result=}"
