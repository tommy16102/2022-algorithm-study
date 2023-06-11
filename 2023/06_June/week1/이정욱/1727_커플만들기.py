import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int,input().split())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))

if n > m:
    l1, l2 = l2, l1
    n,m = m,n

dp = [[0 for _ in range(m)] for _ in range(n)]

l1.sort()
l2.sort()

dp[0][0] = abs(l1[0] - l2[0])

for j in range(1,m-(n-1)):
    dp[0][j] = min(abs(l1[0] - l2[j]), dp[0][j-1])

for i in range(1, n):
    for j in range(i, m - (n - i - 1)):
        if i == j:
            dp[i][j] = dp[i - 1][j - 1] + abs(l1[i] - l2[j])
        else:
            dp[i][j] = min(dp[i - 1][j - 1] + abs(l1[i] - l2[j]), dp[i][j - 1])

print(dp[n-1][m-1])
