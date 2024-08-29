class Solution:
    def lengthOfLastWord(self, s: str) -> int:  # noqa
        return len(s.strip().split()[-1])


if __name__ == '__main__':
    _s = "   fly me   to   the moon  "
    _expected = 4
    _got = Solution().lengthOfLastWord(_s)

    assert _got == _expected, f"Test case failed: expected={_expected}, got={_got}"
