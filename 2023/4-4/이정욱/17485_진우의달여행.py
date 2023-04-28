import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int,input().split())
space = []

for _ in range(n):
    arr = list(map(int,input().split()))
    space.append(arr)

dp = [[[1e10,1e10,1e10] for _ in range(m)] for _ in range(n)]

for i in range(m):
    for j in range(3):
        dp[0][i][j] = space[0][i]

# print(dp)

def cango(i,j):
    if i < 0 or i >= n or j < 0 or j >= m: return False
    return True

def get(i,j,k):
    if cango(i,j): return dp[i][j][k]
    else: return 1e10

for i in range(1,n):
    for j in range(m):
        dp[i][j][0] = space[i][j] + min([get(i-1,j-1,1),get(i-1,j-1,2)])
        dp[i][j][1] = space[i][j] + min([get(i-1,j,0),get(i-1,j,2)])
        dp[i][j][2] = space[i][j] + min([get(i-1,j+1,0),get(i-1,j+1,1)])
# for e in dp:
    # print(e)

res = 1e10
for i in range(m):
    res = min(res,min(dp[n-1][i]))
print(res)