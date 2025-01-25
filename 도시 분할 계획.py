import sys
lines = sys.stdin.read().strip().split("\n")
data = [list(map(int, line.split(' '))) for line in lines]
question = data[0]
data = data[1:]
sorted_data = sorted(data, key = lambda x : x[2])
ans = 0
i = 0
check = {}
j = 0
trees = []
count = 0
for c in range(1, question[0] + 1):
    check[c] = -1
while i < question[0] - 2:
    if check[sorted_data[j][0]] == -1 and check[sorted_data[j][1]] == -1:
        trees.append([])
        trees[count].append(sorted_data[j][0])
        trees[count].append(sorted_data[j][1])
        check[sorted_data[j][0]] = count
        check[sorted_data[j][1]] = count
        count += 1
        i += 1
        ans += sorted_data[j][2]
    elif check[sorted_data[j][0]] != -1 and check[sorted_data[j][1]] == -1:
        trees[check[sorted_data[j][0]]].append(sorted_data[j][1])
        check[sorted_data[j][1]] = check[sorted_data[j][0]]
        i += 1
        ans += sorted_data[j][2]
    elif check[sorted_data[j][0]] == -1 and check[sorted_data[j][1]] != -1:
        trees[check[sorted_data[j][1]]].append(sorted_data[j][0])
        check[sorted_data[j][0]] = check[sorted_data[j][1]]
        i += 1
        ans += sorted_data[j][2]
    elif check[sorted_data[j][0]] != check[sorted_data[j][1]]:
        if len(trees[check[sorted_data[j][0]]]) > len(trees[check[sorted_data[j][1]]]):
            trees[check[sorted_data[j][0]]].extend(trees[check[sorted_data[j][1]]])
            a = check[sorted_data[j][1]]
            for item in trees[check[sorted_data[j][1]]]:
                check[item] = check[sorted_data[j][0]]
            trees[a] = []
        else:
            trees[check[sorted_data[j][1]]].extend(trees[check[sorted_data[j][0]]])
            a = check[sorted_data[j][0]]
            for item in trees[check[sorted_data[j][0]]]:
                check[item] = check[sorted_data[j][1]]
            trees[a] = []
        i += 1
        ans += sorted_data[j][2]
    j += 1
print(ans)
