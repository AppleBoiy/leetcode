class Solution:
    def reverseWords(self, s: str) -> str:  # noqa
        words = s.split()
        return " ".join(words[::-1])


if __name__ == '__main__':
    _s = "  hello world  "
    _expected = "world hello"
    _got = Solution().reverseWords(_s)

    assert _got == _expected, f"Test case failed: expected={_expected}, got={_got}"
