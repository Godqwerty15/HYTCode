import sys
question = list(map(int, sys.stdin.readline().split()))
ary = []
for _ in range(question[0]):
    ary.append(int(sys.stdin.readline()))
tree = [0] * (len(ary) * 4)
def init(start, end, index):
    if start == end:
        tree[index] = ary[start]
        return tree[index]
    mid = (start + end) // 2
    tree[index] = (init(start, mid, index * 2) * init(mid + 1, end, index * 2 + 1)) % 1000000007
    return tree[index]
def update(start, end, index, what, value1, value2):
    if what < start or what > end:
        return tree[index]
    if start == end:
        tree[index] = value2
        return tree[index]
    mid = (start + end) // 2
    tree[index] = update(start, mid, index * 2, what, value1, value2) * update(mid + 1, end, index * 2 + 1, what, value1, value2) % 1000000007
    return tree[index]
def interval_sum(start, end, index, left, right):
    if left > end or right < start:
        return 1
    if left <= start and right >= end:
        return tree[index]
    mid = (start + end) // 2
    return (interval_sum(start, mid, index * 2, left, right) * interval_sum(mid + 1, end, index * 2 + 1, left, right)) % 1000000007
init(0, len(ary) - 1, 1)
for _ in range(question[1] + question[2]):
    quest = list(map(int, sys.stdin.readline().split()))
    if quest[0] == 1:
        update(0, len(ary) - 1, 1, quest[1] - 1, ary[quest[1] - 1], quest[2])
        ary[quest[1] - 1] = quest[2]
    else:
        print(interval_sum(0, len(ary) - 1, 1, quest[1] - 1, quest[2] - 1))
