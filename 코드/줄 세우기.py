import sys
sys.setrecursionlimit(10**6)
lines = sys.stdin.read().strip().split("\n")
data = [list(map(int, line.split(' '))) for line in lines]
question = data[0]
data = data[1:]
check = {}
my_dict = {}
for i in range(1,question[0]+1):
    check[i] = 0
    my_dict[i] = []
for item in data:
    my_dict[item[1]].append(item[0])
def line(n):
    for item in my_dict[n]:
        if check[item] == 0:
            line(item)
    if check[n] == 0:
        print(n, end = ' ')
        check[n] = 1
for i in range(1,question[0] + 1):
    line(i)
