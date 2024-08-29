#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> dp;

    bool isMatch(string& s, string& p, const int i, const int j) // NOLINT(*recursion*)
    {
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (j == p.size())
        {
            return dp[i][j] = i == s.size();
        }

        const bool firstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            return dp[i][j] = isMatch(s, p, i, j + 2) || (firstMatch && isMatch(s, p, i + 1, j));
        }

        return dp[i][j] = firstMatch && isMatch(s, p, i + 1, j + 1);
    }

public:
    bool isMatch(string s, string p)
    {
        dp = vector(s.size() + 1, vector(p.size() + 1, -1));
        return isMatch(s, p, 0, 0);
    }
};

int main()
{
    const string s = "aa";
    const string p = "a";
    cout << boolalpha << Solution().isMatch(s, p) << endl;
    return 0;
}
