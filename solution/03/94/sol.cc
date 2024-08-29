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
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        string res;
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (isalpha(c)) {
                res.push_back(c);
            } else if (c == '[') {
                nums.push(num);
                strs.push(res);
                num = 0;
                res.clear();
            } else {
                string tmp = res;
                for (int i = 1; i < nums.top(); i++) {
                    res += tmp;
                }
                res = strs.top() + res;
                nums.pop();
                strs.pop();
            }
        }
        return res;
    }
};