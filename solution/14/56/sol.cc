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
private:
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c) {
        c = tolower(c);
        for (char v : vowels) {
            if (c == v) {
                return true;
            }
        }
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                cnt++;
            }
        }
        ans = cnt;
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) {
                cnt++;
            }
            if (isVowel(s[i - k])) {
                cnt--;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};