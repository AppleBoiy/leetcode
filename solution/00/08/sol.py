MAX_INT = 2 ** 31 - 1
MIN_INT = -2 ** 31


class Solution:
    def myAtoi(self, s: str) -> int:  # noqa
        s = s.strip()
        if not s:
            return 0
        if not s[0].isnumeric() and s[0] not in ["-", "+"]:
            return 0
        sign = -1 if s[0] == "-" else 1
        if s[0] in ["-", "+"]:
            s = s[1:]
        num = 0
        for c in s:
            if not c.isnumeric():
                break
            num = num * 10 + int(c)
            if num * sign > MAX_INT:
                return MAX_INT
            if num * sign < MIN_INT:
                return MIN_INT
        return num * sign


if __name__ == '__main__':
    s = "1337c0d3"
    expected = 1337

    solution = Solution()
    result = solution.myAtoi(s)
    assert result == expected, f"{result=}, {expected=}"
