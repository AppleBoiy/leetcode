from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:  # noqa
        """45. Jump Game II"""
        n = len(nums)
        jumps = cur_end = cur_farthest = 0
        for i in range(n - 1):
            cur_farthest = max(cur_farthest, i + nums[i])
            if i == cur_end:
                jumps += 1
                cur_end = cur_farthest
        return jumps
