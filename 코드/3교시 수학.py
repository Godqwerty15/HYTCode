import sys
from collections import deque
q = deque()
q.append([1,1])
num = 1
N = int(sys.stdin.readline())
ans = 0
real_ans = []
no = []
test = 1
for _ in range(55):
    no.append(test)
    test *= 2
for i in range(N-1):
    for _ in range(num):
        temp = q.popleft() 
        if (temp[0] - 1) % 3 == 0 and ((temp[0] - 1) / 3) % 2 == 1 and (temp[0] - 1) / 3 >= 2:
            q.append([(temp[0] - 1) / 3, temp[1] + 1])
            num += 1
            if i == N - 2:
                ans += 1
                real_ans.append((temp[0] - 1) / 3)
        q.append([temp[0] * 2, temp[1] + 1])
        if i == N - 2:
            ans += 1
            real_ans.append(temp[0] * 2)
if N == 1:
    print(1)
    print(1)
    sys.exit()
print(ans)
real_ans.sort()
for item in real_ans:
    print(int(item))
