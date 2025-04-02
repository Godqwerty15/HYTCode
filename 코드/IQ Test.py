import sys
N = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))
if len(data) < 2:
    print('A')
    sys.exit()
temp = 0
ans = 0
ans_num = -1000000000000
def check(a, b, s, n):
    global N
    global ans
    global ans_num
    if n == N - 1 and s * a + b == data[n]:
        if ans_num != data[n] * a + b:
            ans += 1
            ans_num = data[n] * a + b
        return
    if s * a + b == data[n]:
        check(a, b, s * a + b, n + 1)
    else:
        return
while(True):
    a = temp
    b = data[1] - data[0] * temp
    check(a, b, data[0], 1)
    if temp == 100000:
        break
    temp += 1
temp = -1
while(True):
    a = temp
    b = data[1] - data[0] * temp
    check(a, b, data[0], 1)
    if temp == -100000:
        break
    temp -= 1
if ans == 1:
    print(ans_num)
elif ans == 0:
    print('B')
else:
    print('A')
