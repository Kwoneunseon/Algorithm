
nums = [2,7,11,15]
target =9

for i, n in enumerate(nums):
    complement = target - n

    if complement in nums[i+1:]:
        print (i, nums[i+1:].index(complement)+i+1 )