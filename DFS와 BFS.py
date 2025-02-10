import sys
sys.setrecursionlimit(10**6)
question = list(map(int, sys.stdin.readline().split()))
data = []
for _ in range(question[1]):
    data.append(list(map(int, sys.stdin.readline().split())))
my_dict = {}
for i in range(1, question[0] + 1):
    my_dict[i] = set()
for item in data:
    my_dict[item[0]].add(item[1])
    my_dict[item[1]].add(item[0])
for i in range(1, question[0] + 1):
    my_dict[i] = sorted(my_dict[i])
DFS_check = set()
BFS_check = set()
def DFS(n):
    DFS_check.add(n)
    print(n, end = ' ')
    for item in my_dict[n]:
        if item not in DFS_check:
            DFS(item)
def BFS(N):
    new_N = []
    for item in N:
        if item not in BFS_check:
            BFS_check.add(item)
            print(item, end = ' ')
            for comp in my_dict[item]:
                new_N.append(comp)
    if new_N:
        BFS(new_N)
DFS(question[2])
print("")
N = set([question[2]])
BFS(N)
