import sys
question = list(map(int, sys.stdin.readline().split()))
ary = [i for i in range(1, question[0] + 1)]
tree = [0] * (len(ary) * 4)
def init(start, end, index):
    if start == end:
        tree[index] = [ary[start] , 1]
        return tree[index]
    mid = (start + end) // 2
    A = init(start, mid, index * 2)
    B = init(mid + 1, end, index * 2 + 1)
    tree[index] = [A[0] + B[0], A[1] + B[1]]
    return tree[index]
def update(start, end, index, what, value):
    if what < start or what > end:
        return
    tree[index] += value
    if start == end:
        return
    mid = (start + end) // 2
    update(start, mid, index * 2, what, value)
    update(mid + 1, end, index * 2 + 1, what, value)
def new_update(index, value):
    if index * 2 < len(tree):
        if type(tree[index*2]) == list:
            if tree[index*2][1] >= value:
                tree[index*2][1] -= 1
                new_update(index * 2, value)
            else:
                tree[index*2+1][1] -= 1
                new_update(index * 2 + 1, value - tree[index*2][1])
        else:
            print(tree[index][0], end = '')
            return
    else:
        print(tree[index][0], end = '')
        return
def interval_sum(start, end, index, left, right):
    if left > end or right < start:
        return 0
    if left <= start and right >= end:
        return tree[index]
    mid = (start + end) // 2
    return interval_sum(start, mid, index * 2, left, right) + interval_sum(mid + 1, end, index * 2 + 1, left, right)
init(0, len(ary) - 1, 1)
j = question[1]
temp = question[0]
print('<', end = '')
for i in range(question[0]):
    new_update(1, j)
    if i == question[0] - 1:
        print('>', end = '')
        break
    else:
        print(', ', end = '')
    j = (j + question[1] - 1) % (temp - 1)
    if j == 0:
        j = temp - 1
    temp -= 1
