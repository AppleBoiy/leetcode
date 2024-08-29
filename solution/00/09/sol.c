#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(const int x)
{
    if (x < 0)
    {
        return false;
    }

    int rev = 0;
    int temp = x;

    while (temp)
    {
        int pop = temp % 10;
        temp /= 10;

        if (rev > (INT_MAX / 10) || (rev == INT_MAX / 10 && pop > 7))
        {
            return false;
        }
        if (rev < (INT_MIN / 10) || (rev == INT_MIN / 10 && pop < -8))
        {
            return false;
        }

        rev = rev * 10 + pop;
    }

    return rev == x;
}


int main()
{
    const int x = 121;
    printf("%s\n", isPalindrome(x) ? "true" : "false");
    return 0;
}
