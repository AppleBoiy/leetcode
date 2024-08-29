class Solution:
    def longestPalindrome(self, s: str) -> str:  # noqa
        n = len(s)
        if n == 0:
            return ""
        if n == 1:
            return s
        dp = [[False] * n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True
        max_len = 1
        start = 0
        for j in range(1, n):
            for i in range(j):
                if s[i] == s[j]:
                    if j - i < 3:
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = False
                if dp[i][j]:
                    cur_len = j - i + 1
                    if cur_len > max_len:
                        max_len = cur_len
                        start = i
        return s[start:start + max_len]


def main():
    s = Solution()
    assert (result := s.longestPalindrome("babad")) == "bab", f"unexpected {result=}"
    assert (result := s.longestPalindrome("cbbd")) == "bb", f"unexpected {result=}"
    assert (result := s.longestPalindrome("a")) == "a", f"unexpected {result=}"

    print("PASSED")


if __name__ == '__main__':
    main()
