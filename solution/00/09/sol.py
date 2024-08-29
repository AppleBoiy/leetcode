class Solution:
    def isPalindrome(self, x: int) -> bool:  # noqa
        return str(x) == str(x)[::-1]


if __name__ == '__main__':
    x = 121
    expected = True

    solution = Solution()
    result = solution.isPalindrome(x)
    assert result == expected, f"{result=}, {expected=}"
