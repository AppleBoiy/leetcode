class Solution:
    def isPalindrome(self, s: str) -> bool:  # noqa
        strs = [char.lower() for char in s if char.isalnum()]
        return strs == strs[::-1]
