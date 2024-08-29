static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) {
            return n;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (res >= n - i || res > n / 2) {
                break;
            }
            unordered_map<double, int> map;
            for (int j = i + 1; j < n; j++) {
                double slope = points[i][0] == points[j][0] ? INT_MAX : (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                map[slope]++;
            }
            for (auto& p : map) {
                res = max(res, p.second + 1);
            }
        }
        return res;
    }
};