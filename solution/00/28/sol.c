#include <stdio.h>
#include <assert.h>
#include <string.h>

int strStr(const char* haystack, const char* needle)
{
    if (!*needle)
    {
        return 0;
    }
    const int m = strlen(haystack), n = strlen(needle);
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

void testStrStr()
{
    // Test case 1: needle is found at the beginning
    assert(strStr("hello", "he") == 0);

    // Test case 2: needle is found in the middle
    assert(strStr("hello", "ll") == 2);

    // Test case 3: needle is found at the end
    assert(strStr("hello", "lo") == 3);

    // Test case 4: needle is the whole haystack
    assert(strStr("hello", "hello") == 0);

    // Test case 5: needle is not found
    assert(strStr("hello", "world") == -1);

    // Test case 6: needle is an empty string
    assert(strStr("hello", "") == 0);

    // Test case 7: haystack is empty
    assert(strStr("", "a") == -1);

    // Test case 8: both haystack and needle are empty
    assert(strStr("", "") == 0);

    // Test case 9: needle is larger than haystack
    assert(strStr("hi", "hello") == -1);

    printf("All tests passed!\n");
}

int main()
{
    testStrStr();
    return 0;
}
