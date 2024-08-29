class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, maxSum = nums[0], currentMax = 0;
        int minSum = nums[0], currentMin = 0;

        for (int num : nums) {
            totalSum += num;

            currentMax = max(currentMax + num, num);
            maxSum = max(maxSum, currentMax);

            currentMin = min(currentMin + num, num);
            minSum = min(minSum, currentMin);
        }

        if (maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};