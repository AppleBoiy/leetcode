class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(result, combination, 1, n, k);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& combination, int start, int n, int k) {
        if (k == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= n; i++) {
            combination.push_back(i);
            backtrack(result, combination, i + 1, n, k - 1);
            combination.pop_back();
        }
    }
};