from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:  # noqa
        nums = sorted(nums1 + nums2)

        i = len(nums) // 2
        if len(nums) % 2 != 0:
            return nums[i]
        return (nums[i - 1] + nums[i]) / 2
