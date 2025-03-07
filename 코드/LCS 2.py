import sys
import bisect
sys.setrecursionlimit(10**6)
fake_first = sys.stdin.readline().strip()
fake_second = sys.stdin.readline().strip()
ans = 0
first = ""
second = ""
for i in range(len(fake_first)):
    if fake_first[i] in fake_second:
        first += fake_first[i]
for i in range(len(fake_second)):
    if fake_second[i] in fake_first:
        second += fake_second[i]
data = {}
for i in range(len(second)):
    if second[i] in data:
        data[second[i]].append(i)
    else:
        data[second[i]] = [i]
memo = [[-1] * 1000 for _ in range(1001)]
ans_string = ""
def LCS(n, s, Max):
    if n == len(first) - 1:
        idx = bisect.bisect_right(data[first[n]], Max)
        if idx < len(data[first[n]]):
            memo[n][Max] = 1
            return s + 1
        return s
    if memo[n][Max] != -1:
        return memo[n][Max] + s
    x = LCS(n + 1, s, Max)
    y = -1
    idx = bisect.bisect_right(data[first[n]], Max)
    if idx < len(data[first[n]]):
        y = LCS(n + 1, s + 1, data[first[n]][idx])
    if x > y:
        memo[n][Max] = x - s
        return x
    elif x <= y:
        memo[n][Max] = y - s
        return y
def LCS_2(n, Max):
    global ans_string
    if n != len(first) - 1:
        idx = bisect.bisect_right(data[first[n]], Max)
        if idx < len(data[first[n]]):
            if memo[n + 1][data[first[n]][idx]] >= memo[n + 1][Max]:
                ans_string += first[n]
                LCS_2(n + 1, data[first[n]][idx])
            else:
                LCS_2(n + 1, Max)
        else:
            LCS_2(n + 1, Max)
    else:
        if memo[n][Max] == 1:
            ans_string += first[n]
if not first:
    print(0)
else:
    print(LCS(0,0,-1))
    LCS_2(0, -1)
    print(ans_string)
