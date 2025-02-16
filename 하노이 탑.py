import sys
sys.setrecursionlimit(10**6)
N = int(sys.stdin.readline())
temp = N
ans = 2 ** N -1
process = []
data = [1]
memo = {1: list(i for i in range(N, 0, -1)), 2 : [0], 3 : [0]}
memo[1].insert(0, 0)
def hanoi_1(N):
    if memo[1][-1] == N:
        if memo[3][-1] == 0 or memo[3][-1] > N:
            memo[3].append(memo[1][-1])
            memo[1].pop()
            process.append([1,3])
        elif memo[2][-1] == 0 or memo[2][-1] > N:
            memo[2].append(memo[1][-1])
            memo[1].pop()
            process.append([1,2])
    elif memo[2][-1] == N:
        if memo[1][-1] == 0 or memo[1][-1] > N:
            memo[1].append(memo[2][-1])
            memo[2].pop()
            process.append([2,1])
        elif memo[3][-1] == 0 or memo[3][-1] > N:
            memo[3].append(memo[2][-1])
            memo[2].pop()
            process.append([2,3])
    elif memo[3][-1] == N:
        if memo[2][-1] == 0 or memo[2][-1] > N:
            memo[2].append(memo[3][-1])
            memo[3].pop()
            process.append([3,2])
        elif memo[1][-1] == 0 or memo[1][-1] > N:
            memo[1].append(memo[3][-1])
            memo[3].pop()
            process.append([3,1])
def hanoi_2(N):
    if memo[1][-1] == N:
        if memo[2][-1] == 0 or memo[2][-1] > N:
            memo[2].append(memo[1][-1])
            memo[1].pop()
            process.append([1,2])
        elif memo[3][-1] == 0 or memo[3][-1] > N:
            memo[3].append(memo[1][-1])
            memo[1].pop()
            process.append([1,3])
    elif memo[2][-1] == N:
        if memo[3][-1] == 0 or memo[3][-1] > N:
            memo[3].append(memo[2][-1])
            memo[2].pop()
            process.append([2,3])
        elif memo[1][-1] == 0 or memo[1][-1] > N:
            memo[1].append(memo[2][-1])
            memo[2].pop()
            process.append([2,1])
    elif memo[3][-1] == N:
        if memo[1][-1] == 0 or memo[1][-1] > N:
            memo[1].append(memo[3][-1])
            memo[3].pop()
            process.append([3,1])
        elif memo[2][-1] == 0 or memo[2][-1] > N:
            memo[2].append(memo[3][-1])
            memo[3].pop()
            process.append([3,2])
print(ans)
if N <= 20:
    if N % 2 == 1:
        for i in range(2, N +1):
            temp = len(data)
            data.append(i)
            for j in range(temp):
                data.append(data[j])
        for item in data:
            hanoi_1(item)
        for item in process:
            print(f"{item[0]} {item[1]}")
    else:
        for i in range(2, N +1):
            temp = len(data)
            data.append(i)
            for j in range(temp):
                data.append(data[j])
        for item in data:
            hanoi_2(item)
        for item in process:
            print(f"{item[0]} {item[1]}")
