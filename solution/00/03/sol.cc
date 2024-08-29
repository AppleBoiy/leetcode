#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    static int lengthOfLongestSubstring(const string& s)
    {
        vector last(128, -1);
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (last[s[i]] >= start)
            {
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }

    static int s(const string& s)
    {
        return lengthOfLongestSubstring(s);
    }

    static const vector<pair<string, int>> testCases;
};

const vector<pair<string, int>> Solution::testCases = {
    {"abcabcbb", 3},
    {"bbbbb", 1},
    {"pwwkew", 3},
    {"", 0}
};

int main()
{
    for (const auto& [input, expected] : Solution::testCases)
    {
        if (const auto actual = Solution::s(input); actual != expected)
        {
            cout << "Test failed!" << endl;
            cout << "Input: " << input << endl;
            cout << "Expected: " << expected << endl;
            cout << "Actual: " << actual << endl;
            return 1;
        }
    }
    cout << "All tests passed!" << endl;
    return 0;
}
