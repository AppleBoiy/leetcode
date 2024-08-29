from typing import List

"""
Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
"""


class Solution:
    def candy(self, ratings: List[int]) -> int:  # noqa
        if len(ratings) == 1:
            return 1

        candies = [1] * len(ratings)
        first, runner, n = ratings[0], ratings[1], len(ratings)
        for i in range(1, n):
            if runner > first:
                candies[i] = candies[i - 1] + 1
            first, runner = runner, ratings[i + 1] if i + 1 < n else 0
        first, runner = ratings[-1], ratings[-2]
        for i in range(n - 2, -1, -1):
            if runner > first:
                candies[i] = max(candies[i], candies[i + 1] + 1)
            first, runner = runner, ratings[i - 1] if i - 1 >= 0 else 0
        return sum(candies)


if __name__ == '__main__':
    solution = Solution()

    assert solution.candy([1, 0, 2]) == 5
    assert solution.candy([1, 2, 2]) == 4

    _case = [60, 80, 100, 100, 100, 100, 100]
    _result = solution.candy(_case)
    print(f"Case: {_case}, Result: {_result}")
