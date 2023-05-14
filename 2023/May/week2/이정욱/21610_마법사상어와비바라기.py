import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(n)]
dir = [(0,-1),(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1)]
cloud = [(n-1,0),(n-1,1),(n-2,0),(n-2,1)]

for _ in range(m):
    d,s = map(int,input().split())
    d -= 1
    dx,dy = dir[d]
    ncloud = []
    for x,y in cloud:
        nx = (x + dx * s) % n
        ny = (y + dy * s) % n
        arr[nx][ny] += 1
        ncloud.append((nx,ny))

    for x,y in ncloud:
        cnt = 0
        for k in range(1,8,2):
            nx = x + dir[k][0]
            ny = y + dir[k][1]
            if nx < 0 or nx >= n or ny < 0 or ny >= n: continue
            if arr[nx][ny] == 0: continue
            cnt += 1
        arr[x][y] += cnt

    next_cloud = []
    for x in range(n):
        for y in range(n):
            if arr[x][y] < 2: continue
            if (x,y) in ncloud: continue
            next_cloud.append((x,y))
            arr[x][y] -= 2

    cloud = next_cloud

res = 0
for e in arr:
    res += sum(e)
print(res)