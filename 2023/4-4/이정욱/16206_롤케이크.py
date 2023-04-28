import sys
import heapq
from functools import cmp_to_key
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int,input().split())
cakes = list(map(int,input().split()))

res = 0
pq = []
cant = 0
for e in cakes:
    if e % 10 != 0: cant += e // 10
    else: heapq.heappush(pq,e)

# print(f"cakes: {cakes}, cant: {cant}")
while pq:
    # print(pq, m)
    here = heapq.heappop(pq)
    if here == 10:
        res += 1
        continue
    if m == 0: break
    res += 1
    next = here - 10
    m -= 1
    if next == 0: continue
    heapq.heappush(pq,next)

if m != 0:
    res += min(m,cant)

print(res)
