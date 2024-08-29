from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:  # noqa
        """55. Jump Game"""
        max_reach = 0
        for i, num in enumerate(nums):
            if i > max_reach:
                return False
            max_reach = max(max_reach, i + num)
        return True
