import sys
from heapq import heappush, heappop
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((c,b))
    graph[b].append((c,a))


dist = [1e10 for _ in range(n+1)]

pq = []
heappush(pq,(0,1))
dist[1] = 0

_m = {}

while pq:
    here_dist, here = heappop(pq)
    if dist[here] != here_dist: continue
    for there_dist, there in graph[here]:
        if dist[there] > dist[here] + there_dist:
            if there in _m:
                _m[there] = here
            else:
                _m[there] = here

            dist[there] = dist[here] + there_dist
            heappush(pq,(dist[there], there))
print(len(_m))
for e in _m:
    print(f"{_m[e]} {e}")