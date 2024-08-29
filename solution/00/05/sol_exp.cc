#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static string longestPalindrome(const string& s)
    {
        if (s.empty()) return "";
        const auto n = s.size();
        int start = 0, max_len = 1;

        auto expandAroundCenter = [&](int left, int right)
        {
            while (left >= 0 && right < n && s[left] == s[right])
            {
                if (right - left + 1 > max_len)
                {
                    start = left;
                    max_len = right - left + 1;
                }
                --left;
                ++right;
            }
        };

        for (int i = 0; i < n; ++i)
        {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
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
