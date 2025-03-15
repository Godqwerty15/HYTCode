import sys
N = int(sys.stdin.readline())
if N < 0:
    N *= -1
    data = []
    ans = [0] * 30
    for i in range(30):
        data.append(3 ** i)
    temp = 0
    pos = 0
    for i in range(30):
        if temp < N:
            temp += data[i]
            ans[i] = 'T'
        if temp == N:
            for j in range(i, -1, -1):
                print(ans[j], end = '')
            sys.exit()
        elif temp > N:
            pos = i
            break
    for i in range(pos, -1, -1):
        if temp - 2 * data[i] >= N:
            temp -= 2 * data[i]
            ans[i] = 1
        elif temp - data[i] >= N:
            temp -= data[i]
            ans[i] = 0
        if temp == N:
            for j in range(pos, -1, -1):
                print(ans[j], end = '')
            sys.exit()
else:
    data = []
    ans = [0] * 30
    for i in range(30):
        data.append(3 ** i)
    temp = 0
    pos = 0
    for i in range(30):
        if temp < N:
            temp += data[i]
            ans[i] = 1
        if temp == N:
            for j in range(i, -1, -1):
                print(ans[j], end = '')
            sys.exit()
        elif temp > N:
            pos = i
            break
    for i in range(pos, -1, -1):
        if temp - 2 * data[i] >= N:
            temp -= 2 * data[i]
            ans[i] = 'T'
        elif temp - data[i] >= N:
            temp -= data[i]
            ans[i] = 0
        if temp == N:
            for j in range(pos, -1, -1):
                print(ans[j], end = '')
            sys.exit()
