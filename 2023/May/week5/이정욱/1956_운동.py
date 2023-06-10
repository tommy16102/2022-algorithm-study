import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

v,e = map(int,input().split())
graph = [[] for _ in range(v+1)]

for _ in range(e):
    a,b,c = map(int,input().split())
    graph[a].append((c,b))

dist = [[1e10 for _ in range(v+1)] for _ in range(v+1)]

for _from in range(1,v+1):
    for _d, _to in graph[_from]:
        dist[_from][_to] = _d

for k in range(1,v+1):
    for i in range(1,v+1):
        for j in range(1,v+1):
            dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])

res = 1e10

for i in range(1,v+1):
    res = min(res, dist[i][i])

if res == 1e10:
    print(-1)
else: print(res)