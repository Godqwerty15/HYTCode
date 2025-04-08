import sys
from decimal import Decimal
print("계산식을 입력하세요 : ")
sys.stdout.flush()
data = sys.stdin.readline().strip()
stack = []
for i in range(len(data)):
    if data[i] != ' ':
        stack.append(data[i])
data = stack
gwal = 0
square = 0
point = 0 
num = 0
num_memo = set([str(i) for i in range(0, 10)])
one_operator = set(['+', '-', '/'])
problem = [0] * (len(data) + 1)
cut = set(['(', ')', '+', '-', '*', '/']) #실수와 수식 분리
for item in data:
    print(item, end = '')
print()
for i in range(len(data)):
    if i == len(data) - 1:
        if data[i] == '(':
            gwal += 1
        if data[i] == ')':
            gwal -= 1
            if gwal < 0:
                problem[i] = 1
        if gwal > 0:
            problem[i+1] = 1
        elif data[i] in one_operator or data[i] == '*':
            problem[i+1] = 1
        elif data[i] == '.':
            problem[i+1] = 1
    elif data[i] == '(':
        gwal += 1
    elif data[i] == ')':
        gwal -= 1
        if gwal < 0:
            problem[i] = 1
    elif data[i] in one_operator:
        point = 0
        if i == 0:
            problem[i] = 1
        else:
            if data[i-1] in one_operator or data[i-1] == '*' or data[i-1] == '.':
                problem[i] = 1
        if data[i+1] == '0' and data[i] == '/':
            problem[i] = 1
    elif data[i] == '*':
        point = 0
        if i == 0:
            problem[i] = 1
        else:
            if data[i-1] in one_operator or data[i-1] == '.':
                problem[i] = 1
            elif data[i-1] == '*':
                square += 1
                if square > 1:
                    problem[i] = 1
    elif data[i] == '.':
        if i == 0:
            problem[i] = 1
        else:
            if point == 0:
                if data[i+1] in one_operator or data[i+1] == '*' or data[i+1] == '(' or data[i+1] == ')':
                    problem[i] = 1
                elif data[i-1] in one_operator or data[i-1] == '*' or data[i-1] == '(' or data[i-1] == ')':
                    problem[i] = 1
                point = 1
            elif point == 1:
                problem[i] = 1
    if data[i] in num_memo:
        num += 1
for i in range(len(problem)):
    if problem[i] == 1:
        print(" " * i + "^ 이 위치에 오류가 있습니다.")
        sys.exit()
if num == 0:
    print("실수 입력값이 없습니다.")
    sys.exit()
def cal(temp):
    stack = 0
    for i in range(len(temp) - 1):
        if temp[i] == temp[i+1] and temp[i] == '*':
            temp[i-1] = temp[i-1] ** temp[i+2]
            stack = i
    if stack != 0:
        for _ in range(3):
            del temp[stack]
    stack = 0
    while True:
        stack = 0
        for i in range(len(temp)):
            if temp[i] == '*':
                temp[i-1] = temp[i-1] * temp[i+1]
                stack = i
                break
            if temp[i] == '/':
                temp[i-1] = temp[i-1] / temp[i+1]
                stack = i
                break
        if stack != 0:
            for _ in range(2):
                del temp[stack]
        else:
            break
    while True:
        stack = 0
        for i in range(len(temp)):
            if temp[i] == '+':
                temp[i-1] = temp[i-1] + temp[i+1]
                stack = i
                break
            if temp[i] == '-':
                temp[i-1] = temp[i-1] - temp[i+1]
                stack = i
                break
        if stack != 0:
            for _ in range(2):
                del temp[stack]
        else:
            break
    return temp[0]
stack = ['']
for item in data:
    if item not in cut:
        stack[-1] += item
    else:
        stack.append(item)
        stack.append('')
data = []
for item in stack:
    if item != '':
        data.append(item)
for i in range(len(data)):
    if data[i] not in cut:
        data[i] = Decimal(data[i])
while True:
    try_num = 0
    gwal = 0
    start = 0
    stack = []
    for i in range(len(data)):
        if gwal == 1:
            if data[i] != ')':
                stack.append(data[i])
            elif data[i] == ')':
                data[start] = cal(stack)
                for _ in range(start, i):
                    del data[start+1]
                    try_num = 1
                break
        if data[i] == '(':
            gwal = 1
            stack = []
            start = i
    if try_num == 0:
        break
data = cal(data)
if int(data) == data:
    print(data)
else:
    print(data.normalize())
