import sys
from itertools import combinations
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
dist = [[1e10 for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    dist[a][b] = 1
    dist[b][a] = 1


for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

res = [1e10,[]]

def get_dist(a,b):
    if a == b: return 0
    return dist[a][b]


for i in range(1,n+1):
    for j in range(i+1,n+1):
        _sum = 0
        for k in range(1,n+1):
            _sum += min(get_dist(i,k), get_dist(j,k))
        if _sum == res[0]:
            res[1].append((i,j))
        elif _sum < res[0]:
            res = [_sum, [(i,j)]]
res[1].sort()
print(f"{res[1][0][0]} {res[1][0][1]} {res[0]*2}")
