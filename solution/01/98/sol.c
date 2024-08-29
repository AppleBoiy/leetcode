int rob(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    int prev = 0, curr = 0;
    for (int i = 0; i < numsSize; i++) {
        int temp = curr;
        curr = fmax(prev + nums[i], curr);
        prev = temp;
    }
    return curr;
}