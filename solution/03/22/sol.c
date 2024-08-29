int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j]) {
                dp[i] = fmin(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    // INT_MAX
    return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
}