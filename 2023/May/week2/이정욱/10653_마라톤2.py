import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,k = map(int,input().split())
course = [tuple(map(int,input().split())) for _ in range(n)]

dp = [[-1 for _ in range(k+1)] for _ in range(n)]

def get_dis(a,b):   
    return abs(course[a][0] - course[b][0]) + abs(course[a][1] - course[b][1])


def go(here,jumped):
    if here == n-1: return 0
    if dp[here][jumped] != -1: return dp[here][jumped]

    dp[here][jumped] = 1e10
    cnt = 0 
    while 1:
        nx = here+cnt+1
        nj = jumped+cnt
        if nx >= n or nj > k: break
        dp[here][jumped] = min(dp[here][jumped], get_dis(here,nx) + go(nx,nj))
        cnt += 1

    return dp[here][jumped] 

print(go(0,0))