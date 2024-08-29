#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_map<char, int> rmp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(const string& s)
    {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 < s.size() && rmp[s[i]] < rmp[s[i + 1]])
            {
                result -= rmp[s[i]];
            }
            else
            {
                result += rmp[s[i]];
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    const string s = "III";
    cout << Solution().romanToInt(s) << endl;
    return 0;
}
