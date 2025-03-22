import sys
N = int(sys.stdin.readline())
ans = []
ans.append(1)
ans2 = []
ans2.append(1)
s = 1
for i in range(N-1):
    if i % 4 == 0:
        ans.append(s+1)
        s += 1
    elif i % 4 == 1:
        ans.append(s+2)
        s += 2
    elif i % 4 == 2:
        ans.append(s-1)
        s -= 1
    elif i % 4 == 3:
        ans.append(s+2)
        s += 2
s = 1
for i in range(N-1):
    if i % 4 == 0:
        ans2.append(s+2)
        s += 2
    elif i % 4 == 1:
        ans2.append(s-1)
        s -= 1
    elif i % 4 == 2:
        ans2.append(s+2)
        s += 2
    elif i % 4 == 3:
        ans2.append(s+1)
        s += 1
for i in range(N):
    if ans[i] > N:
        break
    if i == N - 1:
        print("YES")
        for item in ans:
            print(item, end = ' ')
        sys.exit()
for i in range(N):
    if ans2[i] > N:
        break
    if i == N - 1:
        print("YES")
        for item in ans2:
            print(item, end = ' ')
        sys.exit()
print("NO")
