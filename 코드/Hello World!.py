import sys
N = int(sys.stdin.readline())
if N < 20000 or N > 199999:
    print("No Answer")
    sys.exit()
for A in range(10):
    num = [0,1,2,3,4,5,6,7,8,9]
    o = num[A]
    if N % 10 >= o:
        d = N % 10 - o
    else:
        d = N % 10 - o + 10
    if o == d:
        continue
    else:
        num.remove(o)
        num.remove(d)
    num_set = {}
    for B in range(8):
        if num[B] not in num_set:
            num_set[num[B]] = 'l'
            for C in range(8):
                if num[C] not in num_set:
                    num_set[num[C]] = 'r'
                    for D in range(8):
                        if num[D] not in num_set:
                            num_set[num[D]] = 'e'
                            for E in range(8):
                                if num[E] not in num_set:
                                    num_set[num[E]] = 'h'
                                    for F in range(8):
                                        if num[F] not in num_set:
                                            num_set[num[F]] = 'w'
                                            first = o
                                            second = d + 1000 * o
                                            for item in num_set:
                                                if num_set[item] == 'l':
                                                    first += 110 * item
                                                    second += 10 * item
                                                elif num_set[item] == 'r':
                                                    second += 100 * item
                                                elif num_set[item] == 'h':
                                                    first += 10000 * item
                                                elif num_set[item] == 'w':
                                                    second += 10000 * item
                                                elif num_set[item] == 'e':
                                                    first += 1000 * item
                                            if first + second == N and first >= 10000 and second >= 10000:
                                                print(f"  {first}")
                                                print(f"+ {second}")
                                                print("-------")
                                                print("%7d"%(N))
                                                sys.exit()
                                            del num_set[num[F]]
                                    del num_set[num[E]]
                            del num_set[num[D]]
                    del num_set[num[C]]
            del num_set[num[B]]
print("No Answer")
