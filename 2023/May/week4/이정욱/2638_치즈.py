import sys
from collections import deque
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]

next_q = deque()
_s = 0

for e in arr:
    _s += sum(e)

if _s:
    next_q.append((0,0))

def go():
    global next_q
    visited = [[0 for _ in range(m)] for _ in range(n)]
    checked = [[0 for _ in range(m)] for _ in range(n)]

    for x,y in next_q:
        arr[x][y] = 0
        visited[x][y] = 1

    q = next_q
    next_q = deque()

    while q:
        x,y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m: continue
            if visited[nx][ny]: continue
            if arr[nx][ny]:
                checked[nx][ny] += 1
                if checked[nx][ny] == 2:
                    next_q.append((nx,ny))
            else:
                visited[nx][ny] = 1
                q.append((nx,ny))
    # print("====================")
    # for e in checked:
    #     print(e)
    # print("====================")
    # print(next_q)
    return

res = 0
go()

while next_q:
    res += 1
    go()

print(res)