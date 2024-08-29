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

#endif // LEETCODE_SOLUTION_H__"


class Solution {
public:
    void dfs(VV(int)& res, vector<int>& nums, vector<int>& path, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(res, nums, path, i + 1);
            path.pop_back();
        }
    }

    VV(int) subsets(vector<int>& nums) {
        VV(int) res;
        vector<int> path;
        dfs(res, nums, path, 0);
        return res;
    }
};

