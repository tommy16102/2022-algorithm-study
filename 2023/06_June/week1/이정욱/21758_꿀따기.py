import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
arr = list(map(int,input().split()))

_sum = [0]

for e in arr:
    _sum.append(_sum[-1] + e)

res = 0
# 112
bee1 = 0
hive = n-1

for bee2 in range(1,n-1):
    res = max(res, (_sum[hive+1]-_sum[bee1+1]-arr[bee2]) + (_sum[hive+1]-_sum[bee2+1]))
# 211
hive = 0
bee2 = n-1

for bee1 in range(1,n-1):
    res = max(res, (_sum[bee1]-_sum[hive]) + (_sum[bee2]-_sum[hive]-arr[bee1]))
# 121
bee1 = 0
bee2 = n-1

for hive in range(1,n-1):
    res = max(res,(_sum[hive+1]-_sum[bee1+1]) + (_sum[bee2]-_sum[hive]))


print(res)