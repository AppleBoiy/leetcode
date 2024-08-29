from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:  # noqa
        max_area = 0
        l, r = 0, len(height) - 1
        while l < r:
            max_area = max(max_area, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return max_area


if __name__ == '__main__':
    sol = Solution()

    # Test 1
    height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    assert (result := sol.maxArea(height)) == 49, result

    # Test 2
    height = [1, 1]
    assert (result := sol.maxArea(height)) == 1, result

    # Test 3
    height = [4, 3, 2, 1, 4]
    assert (result := sol.maxArea(height)) == 16, result

    # Test 4
    height = [1, 2, 1]
    assert (result := sol.maxArea(height)) == 2, result

    # Test 5
    height = [1, 2, 4, 3]
    assert (result := sol.maxArea(height)) == 4, result

    print("Passed all tests!")
