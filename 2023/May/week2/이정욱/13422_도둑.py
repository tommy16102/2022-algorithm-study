import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n,m,k = map(int,input().split())
    houses = list(map(int,input().split()))

    if n == m:
        if sum(houses) < k: print(1)
        else: print(0)

    else:
        _m = 0
        for i in range(m):
            _m += houses[i]
        # print(_m)
        res = 0
        for l in range(n):
            # print(f"_m: {_m}")
            if _m < k: res += 1
            nr = (l+m) % n
            # print(f"houses[nr]: {houses[nr]}, houses[l]: {houses[l]}")
            _m = _m + houses[nr] - houses[l]

        # print(f"res: {res}")
        print(res)
