#include <iostream>
#include <cassert>
#include <string>

using namespace std;

class Solution
{
public:
    static int strStr(const string& haystack, const string& needle)
    {
        if (needle.empty())
        {
            return 0;
        }
        const int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++)
        {
            int j = 0;
            for (; j < n; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                return i;
            }
        }
        return -1;
    }
};

void testStrStr()
{
    Solution sol;

    // Test case 1: needle is found at the beginning
    assert(sol.strStr("hello", "he") == 0);

    // Test case 2: needle is found in the middle
    assert(sol.strStr("hello", "ll") == 2);

    // Test case 3: needle is found at the end
    assert(sol.strStr("hello", "lo") == 3);

    // Test case 4: needle is the whole haystack
    assert(sol.strStr("hello", "hello") == 0);

    // Test case 5: needle is not found
    assert(sol.strStr("hello", "world") == -1);

    // Test case 6: needle is an empty string
    assert(sol.strStr("hello", "") == 0);

    // Test case 7: haystack is empty
    assert(sol.strStr("", "a") == -1);

    // Test case 8: both haystack and needle are empty
    assert(sol.strStr("", "") == 0);

    // Test case 9: needle is larger than haystack
    assert(sol.strStr("hi", "hello") == -1);

    cout << "All tests passed!" << endl;
}

int main()
{
    testStrStr();
    return 0;
}
