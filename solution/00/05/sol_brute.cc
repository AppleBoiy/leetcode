#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static string longestPalindrome(const string& s)
    {
        const auto n = s.size();
        if (n == 0) return "";

        int max_len = 1;
        int start = 0;

        auto isPalindrome = [&](int left, int right)
        {
            while (left < right)
            {
                if (s[left] != s[right]) return false;
                ++left;
                --right;
            }
            return true;
        };

        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (isPalindrome(i, j) && j - i + 1 > max_len)
                {
                    start = i;
                    max_len = j - i + 1;
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
