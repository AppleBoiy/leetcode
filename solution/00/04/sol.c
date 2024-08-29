#include <math.h>
#include <stdio.h>
#include <arm/limits.h>

double findMedianSortedArrays(int* nums1, const int nums1Size, int* nums2, const int nums2Size)
{
    if (nums1Size > nums2Size)
    {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int left = 0, right = nums1Size;
    while (left < right)
    {
        const int mid1 = left + (right - left) / 2;
        const int mid2 = (nums1Size + nums2Size + 1) / 2 - mid1;
        if (nums1[mid1] < nums2[mid2 - 1])
        {
            left = mid1 + 1;
        }
        else
        {
            right = mid1;
        }
    }
    const int mid1 = left, mid2 = (nums1Size + nums2Size + 1) / 2 - mid1;
    const int maxLeft1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
    const int minRight1 = mid1 == nums1Size ? INT_MAX : nums1[mid1];
    const int maxLeft2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
    const int minRight2 = mid2 == nums2Size ? INT_MAX : nums2[mid2];
    if ((nums1Size + nums2Size) % 2 == 1)
    {
        return fmax(maxLeft1, maxLeft2);
    }
    return (fmax(maxLeft1, maxLeft2) + fmin(minRight1, minRight2)) / 2.0;
}


int main()
{
    int nums1[] = {1, 3};
    int nums2[] = {2};
    const double result = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("%f\n", result);
    return 0;
}
