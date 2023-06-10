import sys
from collections import deque
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int,input().split())
arr = [list(map(int,input().rstrip())) for _ in range(n)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
visited = [[[1e10,1e10] for _ in range(m)] for _ in range(n)]

q = deque()
q.append((0,0,1))
visited[0][0][1] = 1

while q:
    x,y,can = q.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or ny < 0 or nx >= n or ny >= m: continue
        if visited[nx][ny][can] != 1e10: continue
        if arr[nx][ny] == 1:
            if can:
                visited[nx][ny][0] = visited[x][y][1] + 1
                q.append((nx,ny,0))
        else:
            visited[nx][ny][can] = visited[x][y][can] + 1
            q.append((nx,ny,can))

# for e in visited:
#     print(e)

if min(visited[n-1][m-1]) == 1e10:
    print(-1)
else:
    print(min(visited[n-1][m-1]))