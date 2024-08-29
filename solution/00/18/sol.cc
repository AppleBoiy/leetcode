#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long ll;

#define VV(T) vector<vector<T>>
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define MOD 1000000007

#define VVS vector<vector<string>>

constexpr size_t SIZE = 1000;
constexpr int dp[SIZE] = {};

static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#endif // LEETCODE_SOLUTION_H__

class Solution
{
public:
    static VV(int) fourSum(vector<int>& nums, int target)
    {
        sort(all(nums));
        VV(int) res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                auto l = j + 1;
                auto r = nums.size() - 1;
                while (l < r)
                {
                    if (const ll sum = static_cast<ll>(nums[i]) + nums[j] + nums[l] + nums[r]; sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1])
                        {
                            l++;
                        }
                        while (l < r && nums[r] == nums[r - 1])
                        {
                            r--;
                        }
                        l++;
                        r--;
                    }
                    else if (sum < target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    vector nums = {1, 0, -1, 0, -2, 2};
    constexpr auto target = 0;
    const auto result = Solution::fourSum(nums, target);
    for (const auto& quadruplet : result)
    {
        for (const auto& num : quadruplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
