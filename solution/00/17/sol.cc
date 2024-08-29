#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    static vector<string> letterCombinations(const string& digits)
    {
        if (digits.empty()) return {};

        vector<string> result;
        string current;

        const vector<string> mapping = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz" // 9
        };

        backtrack(digits, 0, current, result, mapping);
        return result;
    }

private:
    static void backtrack( // NOLINT
        const string& digits,
        const int index, string& current,
        vector<string>& result,
        const vector<string>& mapping)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }

        const int digit = digits[index] - '0';
        const string& letters = mapping[digit];
        for (const char letter : letters)
        {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result, mapping);
            current.pop_back();
        }
    }
};


int test_letterCombinations()
{
    const string digits = "23";
    const vector<string> expected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    const auto result = Solution::letterCombinations(digits);
    return expected == result ? 0 : 1;
}

int main(int argc, char* argv[])
{
    return test_letterCombinations();
}
