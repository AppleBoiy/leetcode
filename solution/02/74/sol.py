from typing import List


class SolutionPlaceholder:
    """274. H-Index"""

    def sol1(self, citations: List[int]) -> int:  # noqa
        n = len(citations)
        bucket = [0] * (n + 1)
        for citation in citations:
            bucket[min(citation, n)] += 1
        count = 0
        for i in range(n, -1, -1):
            count += bucket[i]
            if count >= i:
                return i
        return 0

    def sol2(self, citations: List[int]) -> int:  # noqa
        """274. H-Index"""
        citations.sort()
        n = len(citations)
        for i in range(n):
            if citations[i] >= n - i:
                return n - i
        return 0
    

class Solution(SolutionPlaceholder):
    def hIndex(self, citations: List[int]) -> int:  # noqa
        return self.sol2(citations)


if __name__ == '__main__':
    _citation = [3, 0, 6, 1, 5]
    _h = 3
    _s = Solution()
    _a = _s.hIndex(_citation)
    assert _a == _h, f'Error: Expected {_h}, but got {_a}'
