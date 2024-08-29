#ifndef LEETCODE_SOLUTION_H__
#define LEETCODE_SOLUTION_H__

#include <bits/stdc++.h>

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

static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#endif // LEETCODE_SOLUTION_H__

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= first) {
                first = nums[i];
            } else if (nums[i] <= second) {
                second = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};