from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:  # noqa
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        nums[:] = nums[n - k:] + nums[:n - k]


if __name__ == '__main__':
    sol = Solution()

    nums = [1, 2, 3, 4, 5, 6, 7]
    k = 3
    sol.rotate(nums, k)
    assert nums == [5, 6, 7, 1, 2, 3, 4], f"Expected [5, 6, 7, 1, 2, 3, 4], got {nums}"

    nums = [-1, -100, 3, 99]
    k = 2
    sol.rotate(nums, k)
    assert nums == [3, 99, -1, -100], f"Expected [3, 99, -1, -100], got {nums}"
