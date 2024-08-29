#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static string intToRoman(int num)
    {
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result;

        for (const auto& [value, symbol] : values)
        {
            while (num >= value)
            {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};

int main()
{
    cout << Solution::intToRoman(3) << endl;
    cout << Solution::intToRoman(4) << endl;
    cout << Solution::intToRoman(9) << endl;
    cout << Solution::intToRoman(58) << endl;
    cout << Solution::intToRoman(1994) << endl;
    return 0;
}
