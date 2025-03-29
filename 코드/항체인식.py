import sys
import copy
sys.setrecursionlimit(10**6)
question = list(map(int, sys.stdin.readline().split()))
data = []
for _ in range(question[0]):
    data.append(list(map(int, sys.stdin.readline().split())))
memo = set()
new_data = []
for _ in range(question[0]):
    new_data.append(list(map(int, sys.stdin.readline().split())))
test = copy.deepcopy(data)
def find(x, y, s):
    memo.add((x, y))
    test[x][y] = s
    if x > 0:
        if data[x-1][y] == data[x][y] and (x-1, y) not in memo:
            find(x-1, y, s)
    if y > 0:
        if data[x][y-1] == data[x][y] and (x, y-1) not in memo:
            find(x, y-1, s)
    if x < question[0] - 1:
        if data[x+1][y] == data[x][y] and (x+1, y) not in memo:
            find(x+1, y, s)
    if y < question[1] - 1:
        if data[x][y+1] == data[x][y] and (x, y+1) not in memo:
            find(x, y+1, s)
temp = 0
for i in range(question[0]):
    if temp:
        break
    for j in range(question[1]):
        if data[i][j] != new_data[i][j] and (i, j) not in memo:
            find(i, j, new_data[i][j])
            temp = 1
            break
for i in range(question[0]):
    for j in range(question[1]):
        if test[i][j] != new_data[i][j]:
            print("NO")
            sys.exit()
print("YES")
