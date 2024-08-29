#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    static string longestPalindrome(const string& s)
    {
        string t = "#";
        for (const char c : s)
        {
            t += c;
            t += "#";
        }

        const auto n = t.size();
        vector P(n, 0);
        int C = 0, R = 0;
        int max_len = 0, center_index = 0;

        for (int i = 0; i < n; ++i)
        {
            const int mirror = 2 * C - i;

            if (i < R)
            {
                P[i] = min(R - i, P[mirror]);
            }

            while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && t[i + P[i] + 1] == t[i - P[i] - 1])
            {
                P[i]++;
            }

            if (i + P[i] > R)
            {
                C = i;
                R = i + P[i];
            }

            if (P[i] > max_len)
            {
                max_len = P[i];
                center_index = i;
            }
        }

        int start = (center_index - max_len) / 2;
        return s.substr(start, max_len);
    }
};


int main()
{
    const string s = "babad";
    const vector expected = {"bab", "aba"};
    Solution sol;
    const string result = sol.longestPalindrome(s);
    cout << boolalpha << (find(begin(expected), end(expected), result) != end(expected)) << endl;
    return 0;
}
