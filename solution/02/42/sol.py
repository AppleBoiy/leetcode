class Solution:
    def isAnagram(self, s: str, t: str) -> bool:  # noqa
        return sorted(s) == sorted(t)


if __name__ == '__main__':
    _s = Solution()
    s = "anagram"
    t = "nagaram"
    assert _s.isAnagram(s, t) == True, f'{_s.isAnagram(s, t)} != True'
