#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}


int countPairs(int* nums, const int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int ans = 0;
    int* cnt = calloc(1000001, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int vis[1000000] = {0};
        vis[x] = 1;
        char s[12];
        sprintf(s, "%d", x);

        const int len = strlen(s);
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < j; k++) {
                const char temp = s[k];
                s[k] = s[j];
                s[j] = temp;
                const int v = atoi(s);
                vis[v] = 1;
                // Swap back
                s[j] = s[k];
                s[k] = temp;
            }
        }
        for (int v = 0; v < 1000000; v++) {
            if (vis[v]) {
                ans += cnt[v];
            }
        }
        cnt[x]++;
    }

    free(cnt);
    return ans;
}


int main() {
    int nums[] = {1, 1, 1, 1, 1}; //10
    const int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", countPairs(nums, numsSize));
    return 0;
}