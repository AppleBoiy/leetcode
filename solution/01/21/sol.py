from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:  # noqa
        profit, buy = 0, prices[0]
        for price in prices:
            buy = min(buy, price)
            profit = max(profit, price - buy)
        return profit
