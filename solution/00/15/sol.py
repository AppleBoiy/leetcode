from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:  # noqa
        nums.sort()
        res = []
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                sum_ = nums[i] + nums[l] + nums[r]
                if sum_ == 0:
                    res.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif sum_ < 0:
                    l += 1
                else:
                    r -= 1
        return res


if __name__ == '__main__':
    nums = [-1, 0, 1, 2, -1, -4]
    expected = [[-1, -1, 2], [-1, 0, 1]]
    sol = Solution()
    assert (result := sol.threeSum(nums)) == expected, f"unexpected {result=}"
