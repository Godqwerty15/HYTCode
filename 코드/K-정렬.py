import sys
question = list(map(int, sys.stdin.readline().split()))
ary = list(map(int, sys.stdin.readline().split()))
s = 0
pos_dict = {}
num_dict = set()
for i in range(question[0]):
    if ary[i] not in num_dict:
        pos_dict[s] = set()
        temp = i
        while True:
            if ary[temp] not in pos_dict[s]:
                num_dict.add(ary[temp])
                pos_dict[s].add(ary[temp])
                temp += question[1]
                temp %= question[0]
            else:
                break
        s += 1
for item in pos_dict:
    for comp in pos_dict[item]:
        if ary[comp] not in pos_dict[item]:
            print("NO")
            sys.exit()
print("YES")
