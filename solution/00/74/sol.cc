class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == m * n) {
            return false;
        }
        int i = left / n;
        int j = left % n;
        return matrix[i][j] == target;
    }
};