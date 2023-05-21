import sys
from copy import deepcopy
from itertools import combinations
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m,d = map(int,input().split())

arr = [list(map(int,input().split())) for _ in range(n)]

def get_dis(r1,c1,r2,c2):
    return abs(r1-r2) + abs(c1-c2)

c = [i for i in range(m)]
nC3 = list(combinations(c,3))
case궁수list = []

for e in nC3:
    case궁수 = [0 for _ in range(m)]
    for ee in e:
        case궁수[ee] = -1
    case궁수list.append(case궁수)

def findTarget(x,y,arr):
    cankill = []
    for dx in range(1,d+1):
        for dy in range(0,d+1):
            if dx + dy > d: continue
            nx = x - dx
            ny = y + dy
            if 0<=nx<n and 0<=ny<m and arr[nx][ny] == 1:
                cankill.append([dx+dy,ny,-nx])

            nx = x - dx
            ny = y - dy
            if 0<=nx<n and 0<=ny<m and arr[nx][ny] == 1:
                cankill.append([dx+dy,ny,-nx])
            
    cankill.sort()
    if not cankill: return False
            
    return [-cankill[0][2],cankill[0][1]]

def sumArr(arr):
    res = 0
    for e in arr:
        res += sum(e)
    return res

res = 0

for e in case궁수list:
    경우 = deepcopy(arr) + [e]
    궁수위치 = n
    킬 = 0
    while 궁수위치:
        update = []
        update궁수 = []
        for i in range(m):
            update.append((궁수위치,i,0))
            if 경우[궁수위치][i] != -1: continue
            update궁수.append((궁수위치-1,i,-1))
            target = findTarget(궁수위치,i,경우)
            if target != False:
                update.append(target+['킬'])
        for x,y,c in update:
            if c == '킬' :
                if 경우[x][y] != 0:
                    킬 += 1
                    경우[x][y] = 0
            else:
                경우[x][y] = c
        for x,y,c in update궁수:
            경우[x][y] = c

        궁수위치 -= 1
    res = max(res, 킬)

print(res)