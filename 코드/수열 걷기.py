import sys
lines = sys.stdin.read().strip().split("\n")
data = [list(map(int, line.split(' '))) for line in lines]
data = data[:-1]
for i in range(len(data)//2):
    check = {}
    first = 0
    second = 0
    last_pos = 1
    ans = 0
    for j in range(1, len(data[2*i])):
        check[data[2*i][j]] = j
    for j in range(1, len(data[2*i+1])):
        if data[2*i+1][j] in check:
            for c in range(last_pos, check[data[2*i+1][j]]):
                second += data[2*i][c]
            if first > second:
                ans += first + data[2*i+1][j]
            else:
                ans += second + data[2*i+1][j]
            last_pos = check[data[2*i+1][j]] + 1
            first = 0
            second = 0
        else:
            first += data[2*i+1][j]
        if j == len(data[2*i+1]) - 1:
            for c in range(last_pos, len(data[2*i])):
                second += data[2*i][c]
            if first > second:
                ans += first
            else:
                ans += second
    print(ans)
