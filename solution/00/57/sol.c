/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int n = intervalsSize;
    int m = 2;
    int** ans = (int**)malloc(sizeof(int*) * (n + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (n + 1));
    int cnt = 0;
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0]) {
        ans[cnt] = (int*)malloc(sizeof(int) * m);
        ans[cnt][0] = intervals[i][0];
        ans[cnt][1] = intervals[i][1];
        (*returnColumnSizes)[cnt] = m;
        cnt++;
        i++;
    }
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        i++;
    }
    ans[cnt] = (int*)malloc(sizeof(int) * m);
    ans[cnt][0] = newInterval[0];
    ans[cnt][1] = newInterval[1];
    (*returnColumnSizes)[cnt] = m;
    cnt++;
    while (i < n) {
        ans[cnt] = (int*)malloc(sizeof(int) * m);
        ans[cnt][0] = intervals[i][0];
        ans[cnt][1] = intervals[i][1];
        (*returnColumnSizes)[cnt] = m;
        cnt++;
        i++;
    }
    *returnSize = cnt;
    return ans;
}