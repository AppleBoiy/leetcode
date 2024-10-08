class Solution:
    def isMatch(self, s: str, p: str) -> bool:  # noqa
        m, n = len(s), len(p)
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        for i in range(1, n + 1):
            if p[i - 1] == '*':
                dp[0][i] = dp[0][i - 2]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] == '.' or p[j - 1] == s[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or (dp[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == '.'))
        return dp[m][n]


if __name__ == '__main__':
    s = "aa"
    p = "a*"
    expected = True

    solution = Solution()
    result = solution.isMatch(s, p)
    assert result == expected, f"{result=}, {expected=}"

    s = "mississippi"
    p = "mis*is*p*."
    expected = False

    solution = Solution()
    result = solution.isMatch(s, p)
    assert result == expected, f"{result=}, {expected=}"

    s = "ab"
    p = ".*"
    expected = True

    solution = Solution()
    result = solution.isMatch(s, p)
    assert result == expected, f"{result=}, {expected=}"
