import sys
lines = sys.stdin.read().strip().split("\n")
data = [list(map(int, line.split(' '))) for line in lines]
if data[0][0] > data[0][1]:
    print("-1")
else:
    ans = []
    length = 0
    for i in range(1, data[0][1] + 1):
        if i == data[0][2]:
            ans.append(i)
            length += 1
            if length == data[0][0]:
                for item in ans:
                    print(item,end = ' ')
                break
        elif i ^ data[0][2] > i:
            ans.append(i)
            length += 1
            if length == data[0][0]:
                for item in ans:
                    print(item,end = ' ')
                break
    if length < data[0][0]:
        print("-1")
