class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        subMap = {}
        for n in range(len(nums)):
            if nums[n] in subMap:
                return [subMap[nums[n]], n]
            subMap[target-nums[n]] = n