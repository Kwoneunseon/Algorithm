
nums = [2,7,11,15]
target =9

dic_num = {}
for i, num in enumerate(nums):
    dic_num[num]= i

for i, num in enumerate(nums):
    if target - num in dic_num and i != dic_num[target-num]:
        print(i, dic_num[target-num])