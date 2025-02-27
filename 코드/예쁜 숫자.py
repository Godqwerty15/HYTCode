import sys

data = list(map(int, sys.stdin.readline().split()))

def check(p, n):
    pretty_dict = {}
    while n != 0:
        temp = 1
        try_num = 0
        while(temp <= n):
            temp *= p
            try_num += 1
        n -= temp // p
        if try_num not in pretty_dict:
            pretty_dict[try_num] = 1
        else:
            pretty_dict[try_num] += 1
    if len(pretty_dict) == 2:
        one_count = 0
        two_count = 0
        other_count = 0
        for item in pretty_dict:
            if pretty_dict[item] == 1:
                one_count += 1
            elif pretty_dict[item] == 2:
                two_count += 1
            else:
                other_count += 1
        if one_count == 1 and two_count == 1:
            return 1
        elif one_count == 2:
            return 1
        else:
            return 0
    else:
        count_two = 0
        count_one = 0
        count_other = 0
        for item in pretty_dict:
            if pretty_dict[item] == 1:
                count_one += 1
            elif pretty_dict[item] == 2:
                count_two += 1
            else:
                count_other += 1
        if count_one == 1 and count_two >= 2 and count_other == 0:
            return 1
        else:
            return 0
for i in range(1,5):
    print(check(data[0],data[i]),end = ' ')
