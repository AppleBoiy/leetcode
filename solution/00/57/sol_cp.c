static int cmp(const void* a, const void* b) {
    return ((int*)a)[0] - ((int*)b)[0];
}
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int** ans = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    int cnt = 0;
    int i = 0;
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        ans[cnt] = (int*)malloc(sizeof(int) * 2);
        ans[cnt][0] = intervals[i][0];
        ans[cnt][1] = intervals[i][1];
        (*returnColumnSizes)[cnt] = 2;
        cnt++;
        i++;
    }
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        i++;
    }
    ans[cnt] = (int*)malloc(sizeof(int) * 2);
    ans[cnt][0] = newInterval[0];
    ans[cnt][1] = newInterval[1];
    (*returnColumnSizes)[cnt] = 2;
    cnt++;
    while (i < intervalsSize) {
        ans[cnt] = (int*)malloc(sizeof(int) * 2);
        ans[cnt][0] = intervals[i][0];
        ans[cnt][1] = intervals[i][1];
        (*returnColumnSizes)[cnt] = 2;
        cnt++;
        i++;
    }
    *returnSize = cnt;
    return ans;
}