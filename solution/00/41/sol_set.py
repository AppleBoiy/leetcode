from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:  # noqa
        set_nums = set(nums)
        i = 1
        while i in set_nums:
            i += 1
        return i


if __name__ == '__main__':
    nums = [3, 4, -1, 1]
    expected = 2

    sol = Solution()
    assert (result := sol.firstMissingPositive(nums)) == expected, f"unexpected {result=}"
