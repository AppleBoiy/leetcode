struct Interval {
    int start;
    int end;
};

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    struct Interval* intervals_ = (struct Interval*)malloc(sizeof(struct Interval) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        intervals_[i].start = intervals[i][0];
        intervals_[i].end = intervals[i][1];
    }
    struct Interval newInterval_ = {newInterval[0], newInterval[1]};
    struct Interval* ans = (struct Interval*)malloc(sizeof(struct Interval) * (intervalsSize + 1));
    int cnt = 0;
    int i = 0;
    while (i < intervalsSize && intervals_[i].end < newInterval_.start) {
        ans[cnt].start = intervals_[i].start;
        ans[cnt].end = intervals_[i].end;
        cnt++;
        i++;
    }
    while (i < intervalsSize && intervals_[i].start <= newInterval_.end) {
        newInterval_.start = fmin(newInterval_.start, intervals_[i].start);
        newInterval_.end = fmax(newInterval_.end, intervals_[i].end);
        i++;
    }
    ans[cnt].start = newInterval_.start;
    ans[cnt].end = newInterval_.end;
    cnt++;
    while (i < intervalsSize) {
        ans[cnt].start = intervals_[i].start;
        ans[cnt].end = intervals_[i].end;
        cnt++;
        i++;
    }
    *returnSize = cnt;
    int** ret = (int**)malloc(sizeof(int*) * cnt);
    *returnColumnSizes = (int*)malloc(sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++) {
        ret[i] = (int*)malloc(sizeof(int) * 2);
        ret[i][0] = ans[i].start;
        ret[i][1] = ans[i].end;
        (*returnColumnSizes)[i] = 2;
    }
    return ret;
}