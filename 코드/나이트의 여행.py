import sys
memo = {0 : [2, 4, 2, 4], 1 : [1, 3], 2 : [2, 2, 4]}
def first(n):
    if n == 0:
        return 0
    if n == 1:
        return 3
    if n == 2:
        return 2
    if n == 3:
        return 3
    else:
        return (n // 4) * 2 + n % 4
def knight(x, y):
    if x < 0:
        x *= -1
    if y < 0:
        y *= -1
    if x > y:
        x, y = y, x
    if x == 0:
        return first(y)
    temp = y - x
    if temp <= 2:
        if x <= len(memo[temp]):
            return memo[temp][x-1]
        else:
            if temp == 0:
                return (x - 1) // 3 * 2 + 2
            if temp == 1:
                return (x + 1) // 3 * 2 + 1
            if temp == 2:
                return x // 3 * 2 + 2
    if temp % 4 == 0:
        if x <= temp - 3:
            return first(temp) + (x + 3) // 4 * 2
        else:
            return first(temp) + temp // 4 * 2 + (x - temp + 2) // 3 * 2
    elif temp % 4 == 1:
        if x <= temp - 3:
            return first(temp) + (x + 2) // 4 * 2
        else:
            return first(temp) + temp // 4 * 2 + (x - temp + 2) // 3 * 2
    elif temp % 4 == 2:
        if x <= temp - 3:
            return first(temp) + (x + 1) // 4 * 2 
        else:
            return first(temp) + temp // 4 * 2 + (x - temp + 2) // 3 * 2
    elif temp % 4 == 3:
        if x <= temp - 3:
            return first(temp) + x // 4 * 2
        else:
            return first(temp) + temp // 4 * 2 + (x - temp + 2) // 3 * 2
while True:
    try:
        X, Y = map(int, sys.stdin.readline().split())
        print(knight(X, Y))
    except:
        break
