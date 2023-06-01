import sys
from collections import deque
from itertools import combinations
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,-1,1]
n,m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
viruses = []

for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            viruses.append((i,j))

ncr = list(combinations(viruses, m))
res = 1e10


def check(vs):
    for i in range(n):
        for j in range(n):
            if vs[i][j] >= 0 or arr[i][j] == 1: continue
            return False
    return True

for case in ncr:
    visited = [[-1 for _ in range(n)] for _ in range(n)]
    for x,y in case:
        visited[x][y] = 0
    q = deque(case)

    while q:
        if len(q[0]) == 2: 
            x,y = q.popleft()
            z = 0
        else: 
            x,y,z = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n  or ny >= n: continue
            if visited[nx][ny] >= 0 or arr[nx][ny] == 1: continue
            
            if arr[x][y] != 2 and arr[nx][ny] == 2: 
                visited[nx][ny] = visited[x][y]
                q.append((nx,ny,1))
            elif arr[x][y] == 2 and arr[nx][ny] == 2:
                visited[nx][ny] = visited[x][y]
                q.append((nx,ny,z+1))
            elif arr[x][y] == 2 and arr[nx][ny] != 2:
                visited[nx][ny] = visited[x][y] + z+1
                q.append((nx,ny))
            else:
                visited[nx][ny] = visited[x][y] + 1
                q.append((nx,ny))

    if not check(visited): continue
    if check(visited):
        c = 0
        for e in visited:
            c = max(c, max(e))
        res = min(res,c)

if res == 1e10:
    print(-1)
else: 
    print(res)
