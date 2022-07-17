str = str(input())

lists = []
for i in range(len(str)):
    lists.append(str[i:])

lists.sort()
for list in lists:
    print(list)