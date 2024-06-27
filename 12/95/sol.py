class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        temp = [num for num in nums if len(str(num)) % 2 == 0]
        print(temp)
        return len(temp)
