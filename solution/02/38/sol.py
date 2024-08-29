from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:  # noqa
        n = len(nums)
        result = [1] * n
        left, right = 1, 1
        for i in range(n):
            result[i] *= left
            left *= nums[i]
            result[n - i - 1] *= right
            right *= nums[n - i - 1]
        return result
