import sys
import heapq
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

pq1 = []
pq_1 = []
level = {}

n = int(input())


def add(p,l):
    heapq.heappush(pq1,(-l,-p))
    heapq.heappush(pq_1,(l,p))
    level[p] = l
    return

def recommend(k):
    if k == 1:
        target = heapq.heappop(pq1)
    else:
        target = heapq.heappop(pq_1)
    l = abs(target[0])
    p = abs(target[1])

    if p in level and  level[p] == l:
        print(p)
    else:
        recommend(k)
    return

def solved(p):
    level[p] = 0
    return

for _ in range(n):
    p,l = map(int,input().split())
    add(p,l)

m = int(input())

for _ in range(m):
    cmd = list(input().split())
    if cmd[0] == "add":
        add(int(cmd[1]),int(cmd[2]))
    elif cmd[0] == "recommend":
        recommend(int(cmd[1]))
    elif cmd[0] == "solved":
        solved(int(cmd[1]))
