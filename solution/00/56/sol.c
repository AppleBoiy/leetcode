#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int n = intervalsSize;
    int m = 2;
    int** ans = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int l = intervals[i][0];
        int r = intervals[i][1];
        if (cnt == 0 || ans[cnt - 1][1] < l) {
            ans[cnt] = (int*)malloc(sizeof(int) * m);
            ans[cnt][0] = l;
            ans[cnt][1] = r;
            (*returnColumnSizes)[cnt] = m;
            cnt++;
        } else {
            ans[cnt - 1][1] = fmax(ans[cnt - 1][1], r);
        }
    }

    *returnSize = cnt;
    return ans;
}