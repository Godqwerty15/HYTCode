import sys
data = list(sys.stdin.readline().strip())
check = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def make(start, end):
    temp = data[start:end+1]
    stack1 = []
    stack2 = []
    for item in temp:
        if item[0] in check:
            stack1.append(item)
            if stack2:
                if stack2[-1] == '*' or stack2[-1] == '/':
                    new1 = stack1.pop()
                    new2 = stack1.pop()
                    new = new2 + new1 + stack2.pop()
                    stack1.append(new)
        else:
            stack2.append(item)
    length = len(stack2)
    stack1.reverse()
    stack2.reverse()
    for _ in range(length):
        new1 = stack1.pop()
        new2 = stack1.pop()
        new = new1 + new2 + stack2.pop()
        stack1.append(new)
    data[start:end+1] = stack1
def make2(start, end):
    temp = data[start+1:end]
    stack1 = []
    stack2 = []
    for item in temp:
        if item[0] in check:
            stack1.append(item)
            if stack2:
                if stack2[-1] == '*' or stack2[-1] == '/':
                    new1 = stack1.pop()
                    new2 = stack1.pop()
                    new = new2 + new1 + stack2.pop()
                    stack1.append(new)
        else:
            stack2.append(item)
    length = len(stack2)
    stack1.reverse()
    stack2.reverse()
    for _ in range(length):
        new1 = stack1.pop()
        new2 = stack1.pop()
        new = new1 + new2 + stack2.pop()
        stack1.append(new)
    data[start:end+1] = stack1
while True:
    h = 0
    start = 0
    end = 0
    for i in range(len(data)):
        if data[i] == '(':
            start = i
        if data[i] == ')':
            end = i
            make2(start, end)
            h = 1
            break
    if h == 0:
        make(0, len(data))
        print(data[0])
        break
