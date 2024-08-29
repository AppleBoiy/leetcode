#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef const int cint;

char* longestPalindrome(const char* s)
{
    cint n = strlen(s);
    if (n == 0) return "";
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int start = 0, max_len = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if (i < n - 1 && s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            start = i;
            max_len = 2;
        }
    }
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = 1;
                start = i;
                max_len = len;
            }
        }
    }
    char* res = malloc(max_len + 1);
    strncpy(res, s + start, max_len);
    res[max_len] = '\0';
    return res;
}

int main()
{
    const char* s = "babad";
    char* result = longestPalindrome(s);
    printf("%s\n", result);
    free(result);
    return 0;
}
