import sys
from copy import deepcopy
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]

state = [0,0,1,1]

def cal():
    x,y,d1,d2 = state
    wards = [0,0,0,0,0,0]

    a = y
    b = y
    cnt = 0

    for i in range(n):
        for j in range(n):
            if i < x:
                if j <= y:
                    wards[1] += arr[i][j]
                else:
                    wards[2] += arr[i][j]
            elif i > x+d1+d2:
                if j <= y-d1+d2-1:
                    wards[3] += arr[i][j]
                else:
                    wards[4] += arr[i][j]
            else:
                if a <= j <= b:
                    wards[5] += arr[i][j]
                elif j < a:
                    if cnt < d1:
                        wards[1] += arr[i][j]
                    else:
                        wards[3] += arr[i][j]
                else:
                    if cnt <= d2:
                        wards[2] += arr[i][j]
                    else:
                        wards[4] += arr[i][j]

        if x <= i <= x+d1+d2:
            if cnt < d1:
                a -= 1
            else:
                a += 1
            if cnt < d2:
                b += 1
            else:
                b -= 1
            cnt += 1
    return wards

res = 1e10

for x in range(n):
    for y in range(n):
        for d1 in range(n):
            for d2 in range(n):
                state = [x,y,d1,d2]
                wards = cal()
                wards[0] = wards[1]
                _,a1,a2,a3,a4,a5 = wards
                if a1 == 0 or a2 == 0 or a3 == 0 or a4 == 0 or a5 == 0:
                    continue
                res = min(res,abs(max(wards)-min(wards)))

print(res)
