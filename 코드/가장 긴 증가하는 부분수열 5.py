import sys
import bisect
N = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))
ans = []
index_ans = []
real_ans = []
memo = {}
s = 1
ans.append(data[0])
index_ans.append(0)
for i in range(N):
    memo[i] = []
for i in range(1, len(data)):
    if data[i] > ans[-1]:
        ans.append(data[i])
        index_ans.append(i)
        s += 1
    else:
        index = bisect.bisect_left(ans, data[i])
        if data[i] < ans[index]:
            memo[index].append(index_ans[index])
            ans[index] = data[i]
            index_ans[index] = i
max_index = index_ans[s-1]
real_ans = [0] * s
real_ans[s-1] = data[max_index]
for i in range(s - 2, -1, -1):
    if index_ans[i] < max_index:
        max_index = index_ans[i]
        real_ans[i] = data[max_index]
    else:
        while True:
            temp = memo[i].pop()
            if temp < max_index:
                max_index = temp
                real_ans[i] = data[temp]
                break
print(s)
for item in real_ans:
    print(item, end = ' ')
