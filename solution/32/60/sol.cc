/*
Modular Arithmetic only k=7 is hard|Number Theoretical Sol
solution by: https://leetcode.com/u/anwendeng/
*/

class Solution
{
public:
    static void pal7(string& s, const int n)
    {
        const string p7[] = {
            "", "7", "77", "5", "77", "7",
            "", "4", "44", "6", "44", "4"
        };
        const int pos = (n - 1) / 2;
        copy(p7[n % 12].begin(), p7[n % 12].end(), s.begin() + pos);
    }

    static string largestPalindrome(const int n, const int k)
    {
        string s(n, '9');
        if (k == 1 || k == 3 || k == 9) return s;

        if (k == 2 || k == 4 || k == 8)
        {
            const int m = (k == 2) ? 2 : (k == 4) ? 4 : 6;
            if (n <= m) return string(n, '8'); //NOLINT(*-return-braced-init-list)
            fill_n(s.begin(), m / 2, '8');
            fill(s.end() - m / 2, s.end(), '8');
        }
        if (k == 5) return s[0] = s.back() = '5', s;

        if (k == 6)
        {
            if (n <= 2) return string(n, '6'); //NOLINT(*-return-braced-init-list)
            s[0] = s.back() = '8';
            if (n % 2 == 0)
                s[n / 2 - 1] = s[n / 2] = '7';
            else
                s[n / 2] = '8';
        }

        if (k == 7) pal7(s, n);

        return s;
    }
};
