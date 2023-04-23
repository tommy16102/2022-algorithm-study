import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
m = int(input())

gil = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    arr = list(map(int,input().split()))
    for j in range(n):
        gil[i][j] = arr[j]

route = list(map(int,input().split()))

def go(start,x):
    global visited
    can_visit[start].append(x)
    for nx in range(n):
        if gil[x][nx] == 0: continue
        if  visited[nx] == 1: continue
        visited[nx] = 1
        go(start,nx)
    return

can_visit = [[] for _ in range(n)]

for i in range(n):
    visited = [[0 for _ in range(n)] for _ in range(n)]
    visited[i] = 1
    go(i,i)

for i in range(m-1):
    if route[i+1]-1 not in can_visit[route[i]-1]:
        print("NO")
        exit()
print("YES")