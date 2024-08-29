from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:  # noqa
        t_counter = Counter(t)
        s_counter = Counter()
        l, r = 0, 0
        min_len = float("inf")
        min_l = 0
        formed = 0
        required = len(t_counter)
        while r < len(s):
            char = s[r]
            s_counter[char] += 1
            if char in t_counter and s_counter[char] == t_counter[char]:
                formed += 1
            while formed == required:
                if r - l + 1 < min_len:
                    min_len = r - l + 1
                    min_l = l
                char = s[l]
                s_counter[char] -= 1
                if char in t_counter and s_counter[char] < t_counter[char]:
                    formed -= 1
                l += 1
            r += 1
        return "" if min_len == float("inf") else s[min_l:min_l + min_len]


if __name__ == '__main__':
    s = "ADOBECODEBANC"
    t = "ABC"
    expected = "BANC"
    assert (result := Solution().minWindow(s, t)) == expected, f"unexpected {result=}"
