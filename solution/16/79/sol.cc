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
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int num : nums) {
            if (mp[k - num] > 0) {
                ans++;
                mp[k - num]--;
            } else {
                mp[num]++;
            }
        }
        return ans;
    }
};