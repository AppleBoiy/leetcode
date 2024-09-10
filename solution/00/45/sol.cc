#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    static int jump(const vector<int>& nums)
    {
        const int n = nums.size();
        if (n == 1)return 0;

        int jumps = 0;
        int currentEnd = 0;
        int currentFarthest = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            currentFarthest = max(currentFarthest, i + nums[i]);
            if (i == currentEnd)
            {
                ++jumps;
                currentEnd = currentFarthest;
            }
        }

        return jumps;
    }
};

class TestRunner
{
public:
    static auto test1() -> void
    {
        const vector nums = {2, 3, 1, 1, 4};
        constexpr int expected = 2;
        const int result = Solution::jump(nums);
        assert(result == expected);
        cout << "Test 1 passed.\n";
    }

    static auto test2() -> void
    {
        const vector nums = {2, 3, 0, 1, 4};
        constexpr int expected = 2;
        const int result = Solution::jump(nums);
        assert(result == expected);
        cout << "Test 2 passed.\n";
    }

    static auto test3() -> void
    {
        const vector nums = {1, 2, 3};
        constexpr int expected = 2;
        const int result = Solution::jump(nums);
        assert(result == expected);
        cout << "Test 3 passed.\n";
    }

    static auto test4() -> void
    {
        const vector nums = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
        constexpr int expected = 3;
        const int result = Solution::jump(nums);
        assert(result == expected);
        cout << "Test 4 passed.\n";
    }

    static void runAllTests()
    {
        test1();
        test2();
        test3();
        test4();
        cout << "All tests passed!\n";
    }
};

int main()
{
    TestRunner::runAllTests();
    return 0;
}
