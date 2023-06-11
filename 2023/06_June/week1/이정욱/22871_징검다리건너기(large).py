import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
arr = list(map(int,input().split()))

dp = [1e10 for _ in range(n+1)]

dp[0] = 0

for j in range(1,n):
    for i in range(0,j):
        k = max((j-i)*(1+abs(arr[i]-arr[j])),dp[i])
        dp[j] = min(k,dp[j])

print(dp[n-1])