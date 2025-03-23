import sys
question = list(map(int, sys.stdin.readline().split()))
pos = list(map(int, sys.stdin.readline().split()))
data = list(map(int, sys.stdin.readline().split()))
if pos[1] == data[1] and (pos[0] >= data[0] and pos[0] <= data[2]):
    print(1)
elif pos[1] > data[1]:
    if pos[0] == data[0]:
        temp1 = pos[0]
    else:
        a = (pos[1] - data[1]) / (pos[0] - data[0])
        b = data[1] - data[0] * a
        temp1 = -(b/a)
    if pos[0] == data[2]:
        temp2 = pos[0]
    else:
        c = (pos[1] - data[3]) / (pos[0] - data[2])
        d = data[3] - data[2] * c
        temp2 = -(d/c)
    if temp1 < 0:
        temp1 = 0
    if temp2 < 0 :
        temp2 = 0
    if temp1 > question[0]:
        temp1 = question[0]
    if temp2 > question[0]:
        temp2 = question[0]
    print("%.7lf"%((temp2 - temp1) / question[0]))
else:
    print(0)
