import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

for t in range(3):
    n = int(input())
    wallet = {}
    total = 0

    for i in range(n):
        worth, num = map(int,input().split())
        wallet[worth] = num
        total += worth * num
    
    if total % 2 == 1:
        print(0)
        continue

    half = total // 2
    dp = [1] + [0 for _ in range(half)]

    for worth in wallet:
        for i in range(half,worth-1,-1):
            if dp[i-worth]:
                for j in range(wallet[worth]):
                    target = i+worth*j
                    if target > half: break
                    dp[target] = 1
    print(dp[half])