import sys
sys.setrecursionlimit(10**6)
class music:
    def __init__(self):
        self.children = []
        self.parent = []
music_list = []
question = sys.stdin.readline()
question = list(map(int, question.split()))
for i in range(question[0]):
    a = music()
    music_list.append(a)
for _ in range(question[1]):
    data = sys.stdin.readline()
    data = list(map(int, data.split()))
    for i in range(1, len(data)):
        for j in range(1, i):
            music_list[data[i] - 1].children.append(data[j])
            music_list[data[j] - 1].parent.append(data[i])
check = {}
ans = []
def line(n):
    if n in check:
        return
    else:
        check[n] = 1
        for item in music_list[n-1].children:
            line(item)
        ans.append(n)
for i in range(1, question[0] + 1):
    line(i)
check = {}
s = 0
for item in ans:
    for node in music_list[item-1].parent:
        if node in check:
            print("0")
            s = 1
            break
    check[item] = 1
if s == 0:
    for item in ans:
        print(item)
