#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static vector<int> getFinalState(vector<int>& nums, int k, const int multiplier) {
        while (k > 0) {
            int minIndex = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }

            nums[minIndex] *= multiplier;
            --k;
        }

        return nums;
    }
};

