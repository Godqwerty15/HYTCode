import sys
N = int(sys.stdin.readline())
nums = []
memo = []
num_length = 0
for _ in range(N):
    data = int(sys.stdin.readline())
    nums.append(data)
    memo.append(data)
    num_length += 1
check = {}
for i in range(num_length):
    check[i] = 0
nums.sort()
ans = 1
for item in memo:
    start = 0
    end = num_length
    now = (num_length + start) // 2
    while item != nums[now]:
        if item < nums[now]:
            end = now
            now = (end + start) // 2
        elif item > nums[now]:
            start = now
            now = (end + start) // 2
    if now == 0 or now == num_length - 1:
        check[now] = 1
    else:
        if check[now - 1] == 1 and check[now + 1] == 1:
            ans += 1
            check[now] = 1
        else:
            check[now] = 1
print(ans)
