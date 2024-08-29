import unittest
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:  # noqa
        """
        Remove duplicates from sorted array I.
        """
        if not nums:
            return 0

        i = 0
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        return i + 1


class TestSolution(unittest.TestCase):
    def test_removeDuplicates(self):
        solution = Solution()
        self.assertEqual(solution.removeDuplicates([1, 1, 2]), 2)
        self.assertEqual(solution.removeDuplicates([0, 0, 1, 1, 1, 2, 2, 3, 3, 4]), 5)
        self.assertEqual(solution.removeDuplicates([1, 1, 1, 1, 1, 1, 1, 1, 1, 1]), 1)


if __name__ == '__main__':
    unittest.main()
