class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        if (n == 0) return ans;
        int i = 0, j = 0;
        int di = 0, dj = 1;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            ans.push_back(matrix[i][j]);
            if (i + di < top || i + di > bottom || j + dj < left || j + dj > right) {
                if (di == 0 && dj == 1) {
                    ++top;
                    di = 1;
                    dj = 0;
                } else if (di == 1 && dj == 0) {
                    --right;
                    di = 0;
                    dj = -1;
                } else if (di == 0 && dj == -1) {
                    --bottom;
                    di = -1;
                    dj = 0;
                } else if (di == -1 && dj == 0) {
                    ++left;
                    di = 0;
                    dj = 1;
                }
            }
            i += di;
            j += dj;
        }
        return ans;
    }
};