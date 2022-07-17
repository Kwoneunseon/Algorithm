str = input()
arr = [0]*26

#ascii 코드 변환을 통해 사용
#a = 97
for s in str :
    arr[ord(s)-97] +=1

for i in arr:
    print(i, end=' ')