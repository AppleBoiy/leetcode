class Solution:
    def strStr(self, haystack: str, needle: str) -> int:  # noqa
        if not needle:
            return 0

        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i + len(needle)] == needle:
                return i

        return -1


if __name__ == '__main__':
    _s = "sadbutsad"
    _needle = "sad"
    _expected = 0

    solution = Solution()
    output = solution.strStr(_s, _needle)
    assert output == _expected, f"{output} != {_expected}"
