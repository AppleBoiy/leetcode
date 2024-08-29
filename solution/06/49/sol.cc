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
    int findNext(const string& senate, int start, char target) {
        int n = senate.size();
        for (int i = start; i < n; i++) {
            if (senate[i] == target) {
                return i;
            }
        }
        for (int i = 0; i < start; i++) {
            if (senate[i] == target) {
                return i;
            }
        }
        return -1;
    }
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int r = 0, d = 0;
        for (char c : senate) {
            if (c == 'R') {
                r++;
            } else {
                d++;
            }
        }
        while (r > 0 && d > 0) {
            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R') {
                    int j = findNext(senate, i + 1, 'D');
                    if (j == -1) {
                        return "Radiant";
                    }
                    senate[j] = 'B';
                    d--;
                } else if (senate[i] == 'D') {
                    int j = findNext(senate, i + 1, 'R');
                    if (j == -1) {
                        return "Dire";
                    }
                    senate[j] = 'B';
                    r--;
                }
            }
        }
        return r > 0 ? "Radiant" : "Dire";
    }
};