import sys
sys.setrecursionlimit(10**6)
question = list(map(int, sys.stdin.readline().split()))
data = [list(map(int, item.split())) for item in sys.stdin.read().strip().split("\n")]
memo = [[[] for _ in range(question[1])] for c in range(question[0])]
for i in range(question[0]):
    for j in range(question[1]):
        if data[i][j] != 0:
            if i + 1 < question[0] and data[i+1][j] != 0:
                memo[i][j].append([data[i+1][j],i+1,j])
            if i - 1 >= 0 and data[i-1][j] != 0:
                memo[i][j].append([data[i-1][j],i-1,j])
            if j + 1 < question[1] and data[i][j+1] != 0:
                memo[i][j].append([data[i][j+1],i,j+1])
            if j - 1 >= 0 and data[i][j-1] != 0:
                memo[i][j].append([data[i][j-1],i,j-1])
temp = 0
ans = 0
search = {}
report = []
pos = 0
now = 0
def check(x, y, s):
    global now
    for item in memo[x][y]:
        if (item[1], item[2]) not in search:
            search[(item[1], item[2])] = s + 1
            report.append([item[1], item[2]])
            now += 1
for i in range(question[0]):
    for j in range(question[1]):
        if len(memo[i][j]) <= 2:
            search = {}
            search[(i,j)] = 0
            report.append([i,j])
            now += 1
            while(True):
                test = now
                for c in range(pos, test):
                    check(report[c][0],report[c][1],search[(report[c][0], report[c][1])])
                for c in range(pos, test):
                    if search[(report[c][0], report[c][1])] > temp:
                        temp = search[(report[c][0], report[c][1])]
                        ans = data[i][j] + data[report[c][0]][report[c][1]]
                    elif search[(report[c][0], report[c][1])] == temp:
                        if data[i][j] + data[report[c][0]][report[c][1]] > ans:
                            ans = data[i][j] + data[report[c][0]][report[c][1]]
                pos = test
                if now == test:
                    break
print(ans)
