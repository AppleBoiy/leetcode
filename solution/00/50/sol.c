double myPow(double x, int n) {
    if (n == INT_MIN) {
        return 1 / x * myPow(1 / x, -(n + 1));
    }

    if (n == 0) return 1;
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    return result;
}