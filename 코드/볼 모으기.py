import sys
N = int(sys.stdin.readline())
data = sys.stdin.readline().strip()
R_data = []
B_data = []
s = 0
temp = 0
ans_R = 0
ans_B = 0
for i in range(N):
    if data[i] == 'R':
        if s == 0:
            temp = 1
            s = 1
        elif s == 2:
            B_data.append(temp)
            temp = 1
            s = 1
        elif s == 1:
            temp += 1
    elif data[i] == 'B':
        if s == 0:
            temp = 1
            s = 2
        elif s == 2:
            temp += 1
        elif s == 1:
            R_data.append(temp)
            temp = 1
            s = 2
    if i == N-1:
        if s == 1:
            R_data.append(temp)
        elif s == 2:
            B_data.append(temp)
if data[0] == 'R' and data[-1] == 'R':
    ans_R = min(sum(R_data) - R_data[0], sum(R_data) - R_data[-1])
    ans_B = sum(B_data)
elif data[0] == 'R' and data[-1] == 'B':
    ans_R = sum(R_data) - R_data[0]
    ans_B = sum(B_data) - B_data[-1]
elif data[0] == 'B' and data[-1] == 'R':
    ans_R = sum(R_data) - R_data[-1]
    ans_B = sum(B_data) - B_data[0]
else:
    ans_B = min(sum(B_data) - B_data[0], sum(B_data) - B_data[-1])
    ans_R = sum(R_data)
print(min(ans_R, ans_B))
