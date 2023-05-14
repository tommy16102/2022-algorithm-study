import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
train = list(map(int, input().split()))
m = int(input())

train_sum = [0]
_s = 0
for t in train:
    _s += t
    train_sum.append(_s)

dp = [[0] * (n + 1) for _ in range(4)]

for i in range(1, 4):
    for j in range(i * m, n + 1):
        if i == 1:
            dp[i][j] = max(dp[i][j - 1], train_sum[j] - train_sum[j - m])

        else:
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + train_sum[j] - train_sum[j - m])

print(dp[3][n])