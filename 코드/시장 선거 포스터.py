import sys
import heapq
n = int(sys.stdin.readline())
start = {}
end = {}
start2 = {}
data = set()
for i in range(n):
    temp = list(map(int, sys.stdin.readline().split()))
    data.add(temp[0])
    data.add(temp[1])
    if temp[0] in start:
        heapq.heappush(start[temp[0]], -i)
    else:
        start[temp[0]] = [-i]
    if temp[1] not in end:
        end[temp[1]] = [i]
    else:
        end[temp[1]].append(i) # 여기서 i번째 인덱스들이 끝남을 저장하는 거임.
    start2[i] = temp[0]
nums = set()
Mnum = -1
data = list(data)
data.sort()
ended = set()
before = -1
for item in data:
    if item in start:
        if Mnum < -start[item][0]:
            if item - before == 1:
                nums.remove(Mnum)
            Mnum = -start[item][0]
            nums.add(-start[item][0])
    if item in end:
        for comp in end[item]:
            ended.add(comp)
        while Mnum in ended or start2[Mnum] > item:
            Mnum -= 1
            if Mnum == -1:
                break
        if Mnum != -1 and Mnum not in nums:
            nums.add(Mnum)
            before = item
print(len(nums))
