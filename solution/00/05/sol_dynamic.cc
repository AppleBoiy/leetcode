#include <bits/stdc++.h>

using namespace std;

static const int _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    static string longestPalindrome(const string& s)
    {
        const auto n = s.size();
        if (n == 0) return "";
        vector dp(n, vector(n, false));

        int start = 0;
        int max_len = 1;

        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                max_len = 2;
            }
        }

        for (int length = 3; length <= n; ++length)
        {
            for (int i = 0; i <= n - length; ++i)
            {
                int j = i + length - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (length > max_len)
                    {
                        start = i;
                        max_len = length;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};

int main()
{
    const string s = "babad";
    cout << Solution::longestPalindrome(s) << endl;
    return 0;
}
