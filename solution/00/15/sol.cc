#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            auto right = nums.size() - 1;

            while (left < right)
            {
                if (const int sum = nums[i] + nums[left] + nums[right]; sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return result;
    }
};


int main(int argc, char* argv[])
{
    vector nums = {-1, 0, 1, 2, -1, -4};
    const auto result = Solution::threeSum(nums);

    for (const auto& triplet : result)
    {
        for (const auto& num : triplet)
        {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}
