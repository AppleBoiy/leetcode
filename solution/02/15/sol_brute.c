//brute force
int findKthLargest(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] < nums[j]) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
    }
    return nums[k - 1];
}