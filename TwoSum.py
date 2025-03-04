class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        hashmap = {} #initializing empty hashmap
        #populating hashmap
        for index, num in enumerate(nums):
            hashmap[num] = index
        for index, num in enumerate(nums):
            n = target - num # finding complement 
            if n in hashmap and hashmap[n] != index: 
                #checking whether complement present in hashmap and ensuring we don't use the same element twice 
                return [index, hashmap[n]]

sol = Solution()
nums = [2,7,11,15]
target = 9
print(f"Output: {sol.twoSum(nums,target)}")