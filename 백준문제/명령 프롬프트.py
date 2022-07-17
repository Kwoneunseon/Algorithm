N = int(input())
strs = []
for i in range(N) :
    strs.append(input())

if N == 1:
    print(strs[0])
else :
    answer =[]
    for idx in range(len(strs[0])):
        #print(strs[0][idx])
        for n_idx in range(N-1) :
            if strs[n_idx][idx] != strs[n_idx+1][idx] :
                answer.append('?')
                break
            if n_idx == N-2:
                answer.append(strs[n_idx][idx])

    print(''.join(answer))
