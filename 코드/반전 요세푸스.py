import sys
N, K, M = map(int, sys.stdin.readline().split())
class Node:
    def __init__(self, num):
        self.num = num
        self.next = None
        self.prev = None
class CLL:
    def __init__(self):
        self.head = None
        self.tail = None
    def push(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
            new_node.next = new_node
            new_node.prev = new_node
            return
        self.tail.next = new_node
        new_node.prev = self.tail
        new_node.next = self.head
        self.head.prev = new_node
        self.tail = new_node
        return
    def erase(self, node):
        if self.head == node and self.tail == node:
            print(self.head.num)
            self.head = None
            self.tail = None
            return
        node.next.prev = node.prev
        node.prev.next = node.next
        print(node.num)
        return
    def travel(self, K, M):
        count = 0
        while self.head:
            current = self.head
            if (count // M) % 2 == 0:
                for _ in range(K-1):
                    current = current.next
                count += 1
                if (count // M) % 2 == 0:
                    self.head = current.next
                    self.tail = current.prev
                else:
                    self.head = current.prev
                    self.tail = current.next
                self.erase(current)
            else:
                for _ in range(K-1):
                    current = current.prev
                count += 1
                if (count // M) % 2 == 0:
                    self.head = current.next
                    self.tail = current.prev
                else:
                    self.head = current.prev
                    self.tail = current.next
                self.erase(current)
    def print_forward(self):
        current = self.head
        print(current.num)
        current = current.next
        while current != self.head:
            print(current.num)
            current = current.next
        return
cll = CLL()
for i in range(1, N + 1):
    cll.push(i)
cll.travel(K, M)
