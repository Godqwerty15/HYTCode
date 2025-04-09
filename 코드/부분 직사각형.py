import sys
trash = sys.stdin.readline()
data = sys.stdin.read().strip().split('\n')
for i in range(len(data)):
    data[i] = data[i] * 2
data = data * 2
memo = [0] * 26 #ord(알파벳) - 65한 값이 인덱스
for i in range(len(data)):
    for j in range(len(data[i])):
        memo[ord(data[i][j])-65] += (i+1) * (j+1) * (len(data) - i) * (len(data[i]) - j)
for item in memo:
    print(item)
