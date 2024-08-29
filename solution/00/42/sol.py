from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:  # noqa
        if not height:
            return 0

        l, r = 0, len(height) - 1
        lmax, rmax = height[l], height[r]
        water = 0

        while l < r:
            if height[l] < height[r]:
                l += 1
                lmax = max(lmax, height[l])
                water += lmax - height[l]
            else:
                r -= 1
                rmax = max(rmax, height[r])
                water += rmax - height[r]

        return water


if __name__ == '__main__':
    _trap = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    _expected = 6
    _got = Solution().trap(_trap)

    assert _got == _expected, f"Test case failed: expected={_expected}, got={_got}"
