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

static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#endif // LEETCODE_SOLUTION_H__

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        VV(int) dp(2, vector<int>(n, 0));

        for (int k = 1; k <= 2; ++k) {
            int maxDiff = -prices[0];
            for (int i = 1; i < n; ++i) {
                dp[k % 2][i] = max(dp[k % 2][i - 1], prices[i] + maxDiff);
                maxDiff = max(maxDiff, dp[(k - 1) % 2][i] - prices[i]);
            }
        }

    return dp[2 % 2].back();
}
};