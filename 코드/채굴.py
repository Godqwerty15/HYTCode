import sys
from collections import deque
N, M, K = map(int, sys.stdin.readline().split())
data = []
for _ in range(N):
    data.append(list(map(int, sys.stdin.readline().split())))
def mine(n):
    queue = deque()
    count = 0
    memo = [[0] * M for _ in range(N)]
    for i in range(N-1):
        if data[i][0] <= n:
            memo[i][0] = 1
            queue.append((i, 0))
            count += 1
        if data[i][M-1] <= n:
            memo[i][M-1] = 1
            queue.append((i, M-1))
            count += 1
    for i in range(1, M-1):
        if data[0][i] <= n:
            memo[0][i] = 1
            queue.append((0, i))
            count += 1
    if data[N-1][0] <= n:
        memo[N-1][0] = 1
        queue.append((N-1, 0))
        count += 1
    if data[N-1][M-1] <= n:
        memo[N-1][M-1] = 1
        queue.append((N-1, M-1))
        count += 1
    while True:
        if not queue:
            return count
        test = queue.popleft()
        if test[0] - 1 > 0 and memo[test[0]-1][test[1]] == 0 and data[test[0] - 1][test[1]] <= n:
            memo[test[0] -1][test[1]] = 1
            queue.append((test[0] - 1, test[1]))
            count += 1
        if test[0] + 1 < N and memo[test[0]+1][test[1]] == 0 and data[test[0] + 1][test[1]] <= n:
            memo[test[0]+1][test[1]] = 1
            queue.append((test[0] + 1, test[1]))
            count += 1
        if test[1] - 1 > 0 and memo[test[0]][test[1]-1] == 0 and data[test[0]][test[1] - 1] <= n:
            memo[test[0]][test[1]-1] = 1
            queue.append((test[0], test[1] - 1))
            count += 1
        if test[1] + 1 < M and memo[test[0]][test[1]+1] == 0 and data[test[0]][test[1] + 1] <= n:
            memo[test[0]][test[1]+1] = 1
            queue.append((test[0], test[1] + 1))
            count += 1
original_data = set([item for sublist in data for item in sublist])
flat_data = []
for i in range(1, 1000001):
    if i in original_data:
        flat_data.append(i)
start = 0
end = len(flat_data) - 1
while True:
    mid = (start + end) // 2
    check = mine(flat_data[mid])
    if check >= K:
        end = mid
    else:
        start = mid + 1
    if start == end:
        print(flat_data[end])
        break
