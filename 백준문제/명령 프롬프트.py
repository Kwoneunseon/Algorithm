N = int(input())
str = list(input())

for _ in range(N-1):
    str2 = list(input())
    for idx in range(len(str)):
        if str[idx] != str2[idx] :
            str[idx] = '?'

print(''.join(str))