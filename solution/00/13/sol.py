class Solution:
    def romanToInt(self, s: str) -> int:  # noqa
        roman = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }
        num = 0
        prev = 0
        for char in s:
            curr = roman[char]
            num += curr
            if curr > prev:
                num -= 2 * prev
            prev = curr
        return num


if __name__ == '__main__':
    _s = "MCMXCIV"
    _expected = 1994
    _got = Solution().romanToInt(_s)

    assert _got == _expected, f"Test case failed: expected={_expected}, got={_got}"
