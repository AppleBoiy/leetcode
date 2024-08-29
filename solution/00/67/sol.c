char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len = len_a > len_b ? len_a : len_b;
    char* res = (char*)malloc(len + 2);
    res[len + 1] = '\0';
    int carry = 0;
    for (int i = 0; i < len; i++) {
        int sum = carry;
        if (i < len_a) {
            sum += a[len_a - 1 - i] - '0';
        }
        if (i < len_b) {
            sum += b[len_b - 1 - i] - '0';
        }
        res[len - i] = sum % 2 + '0';
        carry = sum / 2;
    }
    res[0] = carry + '0';
    if (res[0] == '0') {
        return res + 1;
    }
    return res;
}