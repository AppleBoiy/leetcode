#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int maxArea(const vector<int>& height)
    {
        int left = 0;
        auto right = height.size() - 1;
        int max_area = 0;

        while (left < right)
        {
            int area = static_cast<int>((right - left) * min(height[left], height[right]));
            max_area = std::max(max_area, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max_area;
    }
};

int main()
{
    const vector height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution::maxArea(height) << endl;
    return 0;
}
