import sys
N = int(sys.stdin.readline())
memo = [i for i in range(1,10)]
def check(n):
    temp1 = n % 10
    n //= 10
    temp2 = n % 10
    return (temp1 - temp2)
my_set = set([])
for item in memo:
    my_set.add(item)
s = 9
pos = 0
now = 8
for i in range(pos, now + 1):
    for j in range(10):
        memo.append(memo[i] * 10 + j)
        s += 1
        my_set.add(memo[i] * 10 + j)
pos = now + 1
now = s - 1
for _ in range(30):
    for i in range(pos, now + 1):   
        if memo[i] % 10 + check(memo[i]) >= 0 and memo[i] % 10 + check(memo[i]) < 10:
            if (memo[i] * 10 + memo[i] % 10 + check(memo[i])) not in my_set:
                memo.append(memo[i] * 10 + memo[i] % 10 + check(memo[i]))
                s += 1
                my_set.add(memo[i] * 10 + memo[i] % 10 + check(memo[i]))
    pos = now + 1
    now = s - 1
ans = 0
for item in memo:
    if item <= N:
        ans += 1
print(ans)
