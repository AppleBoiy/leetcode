class Solution:
    @staticmethod
    def pal7(s: list, n: int):
        p7 = [
            "", "7", "77", "5", "77", "7",
            "", "4", "44", "6", "44", "4"
        ]
        pos = (n - 1) // 2
        s[pos:pos + len(p7[n % 12])] = p7[n % 12]

    @staticmethod
    def largestPalindrome(n: int, k: int) -> str:
        s = ['9'] * n
        if k in {1, 3, 9}:
            return ''.join(s)

        if k in {2, 4, 8}:
            m = k if k != 8 else 6
            if n <= m:
                return '8' * n
            s[:m // 2] = ['8'] * (m // 2)
            s[-m // 2:] = ['8'] * (m // 2)

        if k == 5:
            s[0] = s[-1] = '5'
            return ''.join(s)

        if k == 6:
            if n <= 2:
                return '6' * n
            s[0] = s[-1] = '8'
            if n % 2 == 0:
                s[n // 2 - 1] = s[n // 2] = '7'
            else:
                s[n // 2] = '8'

        if k == 7:
            Solution.pal7(s, n)

        return ''.join(s)
