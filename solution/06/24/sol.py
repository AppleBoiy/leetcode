from typing import List


class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:  # noqa
        min_val = arrays[0][0]
        max_val = arrays[0][-1]
        res = 0
        for i in range(1, len(arrays)):
            res = max(res, abs(arrays[i][-1] - min_val), abs(max_val - arrays[i][0]))
            min_val = min(min_val, arrays[i][0])
            max_val = max(max_val, arrays[i][-1])
        return res
