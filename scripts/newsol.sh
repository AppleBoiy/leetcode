#!/usr/bin/env bash

# shellcheck disable=SC2162
read -p "Enter the code: " code # XXYY
first_two=${code:0:2}
last_two=${code:2:2}
mkdir -p solution/"$first_two"/"$last_two"

read -p "Enter extension: " lang # py, js, java, c, cpp
touch solution/"$first_two"/"$last_two"/sol."$lang"

#if c lang append the header
if [ "$lang" == "cc" ]; then
    cat <<EOF > solution/"$first_two"/"$last_two"/sol.cc
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
EOF
fi