bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    bool dp[len + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int wordLen = strlen(wordDict[j]);
            if (i >= wordLen && dp[i - wordLen] && strncmp(s + i - wordLen, wordDict[j], wordLen) == 0) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}