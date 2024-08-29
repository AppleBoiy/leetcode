from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:  # noqa
        prefix = ""
        for i, char in enumerate(strs[0]):
            for word in strs:
                if len(word) == i or word[i] != char:
                    return prefix
            prefix += char
        return prefix


if __name__ == '__main__':
    _s = "a"
    _expected = "a"
    _got = Solution().longestCommonPrefix(_s)

    assert _got == _expected, f"Test case failed: expected={_expected}, got={_got}"
