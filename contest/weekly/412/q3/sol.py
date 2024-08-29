# author: awice
# here: https://leetcode.com/u/awice/

from heapq import heapify, heappop, heappush
from typing import List

MOD = 10 ** 9 + 7


class Solution:
    @staticmethod
    def getFinalState(nums: List[int], k: int, mul: int) -> List[int]:
        if mul == 1:
            return nums
        n = len(nums)

        cnt = [[x, i] for i, x in enumerate(nums)]
        heapify(cnt)
        count = [0] * n

        while k and cnt[0][0] <= 1e9:
            k -= 1
            b, i = heappop(cnt)
            count[i] += 1
            heappush(cnt, [b * mul, i])

        q, r = divmod(k, n)
        cnt.sort()
        for ix, (b, i) in enumerate(cnt):
            count[i] += q + (ix < r)

        for i, c in enumerate(count):
            nums[i] *= pow(mul, c, MOD)
            nums[i] %= MOD

        return nums
