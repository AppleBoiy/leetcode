int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    int l = 0, r = x;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (m < x / m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l == x / l ? l : l - 1;
}