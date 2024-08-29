#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution
{
public:
    static vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    static void backtrack(vector<string>& result, const string& combination, int open, int close, int n)
    {
        if (combination.size() == n * 2)
        {
            result.push_back(combination);
            return;
        }

        if (open < n)
        {
            backtrack(result, combination + "(", open + 1, close, n);
        }
        if (close < open)
        {
            backtrack(result, combination + ")", open, close + 1, n);
        }
    }
};

void testGenerateParenthesis()
{
    const vector<string> expected1 = {"()"};
    const vector<string> result1 = Solution::generateParenthesis(1);
    assert(result1 == expected1);

    const vector<string> expected2 = {"(())", "()()"};
    vector<string> result2 = Solution::generateParenthesis(2);
    sort(result2.begin(), result2.end()); // To compare regardless of order
    assert(result2 == expected2);

    const vector<string> expected3 = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    vector<string> result3 = Solution::generateParenthesis(3);
    sort(result3.begin(), result3.end()); // To compare regardless of order
    assert(result3 == expected3);
}

int main()
{
    testGenerateParenthesis();
    cout << "All tests passed!\n";
    return 0;
}
