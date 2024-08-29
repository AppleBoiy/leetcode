int lengthOfLIS(int* nums, int numsSize) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int len = 0;
    for (int i = 0; i < numsSize; i++) {
        int l = 0, r = len;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (dp[m] < nums[i]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        dp[l] = nums[i];
        if (l == len) {
            len++;
        }
    }
    free(dp);
    return len;
}