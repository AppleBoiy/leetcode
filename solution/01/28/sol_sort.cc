class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] == nums[i - 1] + 1) {
                cur++;
            } else if (nums[i] != nums[i - 1]) {
                ans = max(ans, cur);
                cur = 1;
            }
        }

        return max(ans, cur);
    }
};