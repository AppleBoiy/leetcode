class Solution:
    def loop(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
        if divisor == 1:
            return dividend
        if divisor == -1:
            return -dividend
        if dividend == divisor:
            return 1
        if dividend == -divisor:
            return -1
        if dividend < 0 and divisor < 0:
            return self.loop(-dividend, -divisor)
        if dividend < 0:
            return -self.loop(-dividend, divisor)
        if divisor < 0:
            return -self.loop(dividend, -divisor)

        result = 0
        while dividend >= divisor:
            dividend -= divisor
            result += 1
        return result

    def bit_manipulation(self, dividend, divisor):
        """
        Explanation:
            Dividend = 30, Divisor = 4
            30 = 4 * 2 ^ 2     | + 4 * 2 ^ 1   | + 4 * 2 ^ 0  | + ( 2 since we truncate the decimal part we ignore it)
                30 - (4 << 2)  | 16 - (4 << 1) | 2 - (4 << 0)
                30 - 16        | 14 - 8        | 6 - 4
                14             | 6             | 2
        """
        # in case overflow
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1

        # sign are different if and only if sign of dividend and divisor are different
        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1
        dividend, divisor = abs(dividend), abs(divisor)

        quotient = 0
        for i in range(31, -1, -1):
            if dividend >= divisor << i:
                dividend -= divisor << i
                quotient |= 1 << i
        return sign * quotient

    def divide(self, dividend: int, divisor: int) -> int:
        return self.bit_manipulation(dividend, divisor)

def test():
    assert Solution().divide(10, 3) == 3, f"expected 3, but got {Solution().divide(10, 3)}"
    assert Solution().divide(7, -3) == -2, f"expected -2, but got {Solution().divide(7, -3)}"

    print('PASSED')

def main():
    print(Solution().divide(10, 3))

if __name__ == '__main__':
    test()
