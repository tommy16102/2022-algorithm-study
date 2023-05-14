import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    f = int(input())
    f_set = set()
    cmd = [list(input().rstrip().split()) for _ in range(f)]
    parent = {}
    friends = {}
    
    def find(name):
        if name == parent[name]:
            return name
        
        parent[name] = find(parent[name])
        return parent[name]

    def union(a,b):
        a = find(a)
        b = find(b)
        if a != b:
            parent[b] = a
            friends[a] += friends[b]
        print(friends[a])

    for a,b in cmd:
        if a not in parent:
            parent[a] = a
            friends[a] = 1
        if b not in parent:
            parent[b] = b
            friends[b] = 1
        union(a, b)
