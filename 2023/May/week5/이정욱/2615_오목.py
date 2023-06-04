import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

arr = [list(map(int,input().split())) for _ in range(19)]
dx = [-1,1,0,0,-1,-1,1,1]
dy = [0,0,-1,1,-1,1,-1,1]
reverse = [1,0,3,2,7,6,5,4]

def go(x,y,l,d):
    nx = x + dx[d]
    ny = y + dy[d]
    if nx < 0 or ny < 0 or nx >= 19 or ny >= 19: 
        return l
    
    if arr[nx][ny] != arr[l[0][1]][l[0][0]]:
        return l
    l.append((ny,nx))
    return go(nx,ny,l,d)

# one = go(2,1,[(2,1)],7)
# two= go(2,1,[(2,1)],reverse[7])
# res = one + two
# res.sort()

# print(res)

for i in range(19):
    for j in range(19):
        for k in range(8):
            if arr[i][j] == 0: continue
            one = go(i,j,[(j,i)],k)
            two = go(i,j,[(j,i)],reverse[k])
            res = one + two
            if len(res) == 6:
                res.sort()
                # print(res)
                print(arr[res[0][1]][res[0][0]])
                print(f"{res[0][1]+1} {res[0][0]+1}")
                exit()

print(0)