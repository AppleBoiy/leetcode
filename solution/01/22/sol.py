from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:  # noqa
        """122. Best Time to Buy and Sell Stock II."""
        return sum(max(prices[i + 1] - prices[i], 0) for i in range(len(prices) - 1)
                   if prices[i + 1] > prices[i])
