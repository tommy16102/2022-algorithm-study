import sys
import math
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

t = int(input())

def get_dis(x1,y1,x2,y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)

for _ in range(t):
    x1,y1,r1,x2,y2,r2 = map(int,input().split())
    dis = get_dis(x1,y1,x2,y2)
    _r1 = min(r1,r2)
    _r2 = max(r1,r2)
    r1 = _r1
    r2 = _r2
    if dis == 0:
        if r1 == r2:
            print(-1)
        else: print(0)
    else:
        if dis == r2 - r1 or dis == r1 + r2:
            print(1)
        elif r2 - r1 < dis < r1 + r2:
            print(2)
        else:
            print(0)