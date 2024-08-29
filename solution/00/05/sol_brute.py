def is_palindrome(s: str) -> str:
    return s == s[::-1]


class Solution:
    def longestPalindrome(self, s: str) -> str:  # noqa
        max_len = 1
        p = s[0]
        n = len(s)
        for i in range(n):
            for j in range(i + 1, n + 1):
                if is_palindrome(s[i:j]):
                    if len(s[i:j]) > max_len:
                        max_len = len(s[i:j])
                        p = s[i:j]

        return p


def main():
    s = Solution()
    assert (result := s.longestPalindrome("babad")) == "bab", f"unexpected {result=}"
    assert (result := s.longestPalindrome("cbbd")) == "bb", f"unexpected {result=}"
    assert (result := s.longestPalindrome("a")) == "a", f"unexpected {result=}"

    print("PASSED")


if __name__ == '__main__':
    main()
