import sys
M, N = map(int, sys.stdin.readline().split())
real_data = []
memo = {}
for _ in range(M):
    temp = list(map(int, sys.stdin.readline().split()))
    data = [[x, idx + 1] for idx, x in enumerate(temp)]
    data.sort(key = lambda x: (x[0], x[1]))
    data = [item[1] for item in data]
    equ = []
    for i in range(len(temp)-1):
        if temp[i] == temp[i+1]:
            equ.append(i)
    real_data.append((tuple(data), tuple(equ)))
for item in real_data:
    if item in memo:
        memo[item] += 1
    else:
        memo[item] = 1
ans = 0
for item in memo:
    if memo[item] >= 2:
        ans += memo[item] * (memo[item] - 1) // 2
print(ans)
