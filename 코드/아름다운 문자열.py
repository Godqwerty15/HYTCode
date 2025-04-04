import sys
data = sys.stdin.readline().strip()
T = sys.stdin.readline().strip()
memo = {}
for char in T:
    memo[char] = []
for i in range(len(data)):
    if data[i] in memo:
        memo[data[i]].append(i)
ans = 0

while True:
    for i in range(len(T)):
        if i < len(T) - 1 and memo[T[i+1]] and memo[T[i]]:
            while memo[T[i]][-1] > memo[T[i+1]][-1]:
                memo[T[i]].pop()
                if not memo[T[i]]:
                    print(ans)
                    sys.exit()
            memo[T[i]].pop()
        elif i < len(T) - 1 and (not memo[T[i+1]] or not memo[T[i]]):
            print(ans)
            sys.exit()
        elif i == len(T) - 1 and memo[T[i]]:
            memo[T[i]].pop()
            ans += 1
        elif i == len(T) - 1 and not memo[T[i]]:
            print(ans)
            sys.exit()
