import sys
sys.setrecursionlimit(10**6)
question = list(map(int, sys.stdin.readline().split())) # N, Q
data = list(map(int, sys.stdin.readline().split()))
memo = {}
for i in range(1, question[0] + 1):
    memo[i] = []
for _ in range(question[0] - 1):
    temp = list(map(int, sys.stdin.readline().split()))
    memo[temp[0]].append(temp[1])
    memo[temp[1]].append(temp[0])
visited = set()
def travel(n, s, target):
    if n == target:
        print(int(s) % 1000000007)
        return
    for item in memo[n]:
        if item not in visited:
            visited.add(item)
            travel(item, s + str(data[item - 1]), target)
for _ in range(question[1]):
    temp = list(map(int, sys.stdin.readline().split()))
    visited = set([temp[0]])
    travel(temp[0], str(data[temp[0] - 1]), temp[1])
