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
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        vector<int> cnt1(26);
        vector<int> cnt2(26);

        for (const char& c : word1) {
            cnt1[c - 'a']++;
        }

        for (const char& c : word2) {
            cnt2[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((cnt1[i] == 0) ^ (cnt2[i] == 0)) {
                return false;
            }
        }

        sort(all(cnt1));
        sort(all(cnt2));

        return cnt1 == cnt2;
    }
};