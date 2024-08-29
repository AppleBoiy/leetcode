MAX_INT = 2 ** 31 - 1
MIN_INT = - (2 ** 31)


class Solution:
    def reverse(self, x: int) -> int:  # noqa
        neg = -1 if x < 0 else 1
        num = x * neg

        res = 0
        while num:
            res = res * 10 + num % 10
            num //= 10

        res *= neg
        if res > MAX_INT or res < MIN_INT:
            return 0
        return res


if __name__ == '__main__':
    x = 123
    expected = 321
    solver = Solution().reverse
    assert (result := solver(x)) == expected, f"unexpected {result=}"
