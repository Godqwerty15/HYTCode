import sys
import heapq
question = list(map(int, sys.stdin.readline().split()))
jewel = []
for _ in range(question[0]):
    ex = list(map(int, sys.stdin.readline().split()))
    jewel.append(ex)
bag = []
for _ in range(question[1]):
    ex = int(sys.stdin.readline())
    bag.append(ex)
jewel.sort(key = lambda x : x[0])
bag.sort()
memo = [0] * question[1]
s = 0
for i in range(question[1]):
    if s == question[0]:
        memo[i] = s
    else:
        while bag[i] >= jewel[s][0]:
            if s < question[0]:
                s += 1
                if s == question[0]:
                    break
        memo[i] = s
heap = []
jewel_pos = 0
bag_pos = 0
ans = 0
for i in range(question[1]):
    if i == question[1] - 1:
        jewel[jewel_pos:memo[i]] = sorted(jewel[jewel_pos:memo[i]], key = lambda x : x[1])
        rest = i - bag_pos + 1
        t = memo[i] - jewel_pos
        pos = memo[i] - 1
        while t + len(heap) > 0:
            if rest > 0:
                if heap and t > 0:
                    if jewel[pos][1] > -heap[0]:
                        ans += jewel[pos][1]
                        pos -= 1
                        rest -= 1
                        t -= 1
                    else:
                        ans += -heapq.heappop(heap)
                        rest -= 1
                elif not heap and t > 0:
                    ans += jewel[pos][1]
                    pos -= 1
                    rest -= 1
                    t -= 1
                elif heap and t == 0:
                    ans += -heapq.heappop(heap)
                    rest -= 1
            else:
                break
    else:
        if memo[i] != memo[i+1]:
            jewel[jewel_pos:memo[i]] = sorted(jewel[jewel_pos:memo[i]], key = lambda x : x[1])
            rest = i - bag_pos + 1
            t = memo[i] - jewel_pos
            pos = memo[i] - 1
            while t + len(heap) > 0:
                if rest > 0:
                    if heap and t > 0:
                        if jewel[pos][1] > -heap[0]:
                            ans += jewel[pos][1]
                            pos -= 1
                            rest -= 1
                            t -= 1
                        else:
                            ans += -heapq.heappop(heap)
                            rest -= 1
                    elif not heap and t > 0:
                        ans += jewel[pos][1]
                        pos -= 1
                        rest -= 1
                        t -= 1
                    elif heap and t == 0:
                        ans += -heapq.heappop(heap)
                        rest -= 1
                else:
                    break
            for j in range(jewel_pos, pos + 1):
                heapq.heappush(heap, -jewel[j][1])
            jewel_pos = memo[i]
            bag_pos = i + 1
print(ans)
