/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* res = (int*)malloc((digitsSize + 1) * sizeof(int));
    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        res[i + 1] = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
    }
    res[0] = carry;
    *returnSize = digitsSize + 1;
    if (res[0] == 0) {
        int* tmp = (int*)malloc(digitsSize * sizeof(int));
        for (int i = 0; i < digitsSize; i++) {
            tmp[i] = res[i + 1];
        }
        free(res);
        *returnSize = digitsSize;
        return tmp;
    }
    return res;
}