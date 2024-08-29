#include <stdio.h>


int search(const int* nums, const int numsSize, const int target)
{
    int left = 0, right = numsSize - 1;
    while (left <= right)
    {
        const int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    const int nums[] = {4, 5, 6, 7, 0, 1, 2};
    const int target = 0;
    const int numsSize = sizeof(nums) / sizeof(nums[0]);
    const int result = search(nums, numsSize, target);
    printf("%d\n", result);
}
