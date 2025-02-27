import sys
N = int(sys.stdin.readline())
data = []
data = list(map(int, sys.stdin.readline().split()))
dp = [0] * N
dp[0] = [data[0],1]
for i in range(1, N):
    dp[i] = [dp[i-1][0] + data[i],i+1]
dp.sort(key = lambda x : x[0])
dp.insert(0, [0,0])
small = 922337203685477580
first = -1
second = -1
for i in range(N):
    if abs(dp[i][0] - dp[i+1][0]) < abs(small):
        small = dp[i][0] - dp[i+1][0]
        first = min(dp[i][1],dp[i+1][1]) + 1
        second = max(dp[i][1],dp[i+1][1])
for i in range(1, N+1):
    if abs(dp[i][0]) < abs(small):
        small = dp[i][0]
        first = 1
        second = dp[i][1]
ans = 0
for i in range(first - 1, second):
    ans += data[i]
print(ans)
print(f"{first} {second}")
