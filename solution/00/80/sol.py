from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:  # noqa
        """
        Remove duplicates from sorted array II.
        """
        if not nums:
            return 0

        i = 0
        count = 1
        for j in range(1, len(nums)):
            if nums[j] == nums[i]:
                count += 1
                if count <= 2:
                    i += 1
                    nums[i] = nums[j]
            else:
                count = 1
                i += 1
                nums[i] = nums[j]
        return i + 1
