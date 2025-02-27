import sys
sys.setrecursionlimit(10**6)
N = int(sys.stdin.readline())
data = []
for _ in range(N):
    data.append(list(map(int, sys.stdin.readline().strip())))
my_dict = {}
part_check = set([])
for i in range(N):
    my_dict[i] = []
for i in range(N):
    for j in range(N):
        if data[i][j] == 1:
            my_dict[i].append(j)
            my_dict[j].append(i)
fresh = 0
old = 0
def travel(n, s):
    global fresh
    global old
    if s == 0:
        fresh += 1
    else:
        old += 1
    part_check.add(n)
    for item in my_dict[n]:
        if item not in part_check:
            if s == 0:
                travel(item, 1)
            else:
                travel(item, 0)
ans = 0
for i in range(N):
    fresh = 0
    old = 0
    if i not in part_check and my_dict[i]:
        travel(i, 0)
    ans += max(fresh, old)
ans += N - len(part_check)
print(ans)
