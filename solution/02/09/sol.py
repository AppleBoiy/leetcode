from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:  # noqa
        l, r = 0, 0
        sum_ = 0
        min_len = float("inf")
        while r < len(nums):
            sum_ += nums[r]
            while sum_ >= target:
                min_len = min(min_len, r - l + 1)
                sum_ -= nums[l]
                l += 1
            r += 1
        return min_len if min_len != float("inf") else 0


if __name__ == '__main__':
    target = 7
    nums = [2, 3, 1, 2, 4, 3]
    expected = 2

    assert (result := Solution().minSubArrayLen(target, nums)) == expected, f"unexpected {expected} != {result=}"
