from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:  # noqa
        _dict = {}
        for index, number in enumerate(nums):
            if target - number in _dict:
                return [_dict[target - number], index]
            _dict[number] = index


def main():
    solution = Solution()
    print(solution.twoSum([2, 7, 11, 15], 9))
    print(solution.twoSum([3, 2, 4], 6))
    print(solution.twoSum([3, 3], 6))


if __name__ == '__main__':
    main()
