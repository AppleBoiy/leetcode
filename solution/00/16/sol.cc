#include <bits/stdc++.h>

using namespace std;


class Solution
{
public:
    static int threeSumClosest(vector<int>& nums, const int target)
    {
        const auto n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; ++i)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                const auto sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans - target))
                {
                    ans = sum;
                }
                if (sum < target)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[])
{
    vector nums = {-1, 2, 1, -4};
    constexpr auto target = 1;
    cout << Solution::threeSumClosest(nums, target) << endl;
    return 0;
}

