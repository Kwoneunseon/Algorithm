
nums = [2,7,11,15]
target =9

for i in range(len(nums)):
    for j in range(i+1,len(nums)):
        if target == nums[i] + nums[j]:
            print([i,j])