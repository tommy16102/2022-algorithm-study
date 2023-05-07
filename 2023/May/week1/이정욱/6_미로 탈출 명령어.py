import sys
sys.setrecursionlimit(10**5)

# lrdu
# dlru

d = [(1,0,"d"),(0,-1,"l"),(0,1,"r"),(-1,0,"u")]

def can_go(x,y,r,c,k):
    row = abs(x-r)
    col = abs(y-c)
    remain = k-(row+col)
    
    if remain < 0: return False
    
    if remain%2 == 1:
        return False
    else: 
        return True

def solution(n, m, x, y, r, c, k):
    def go(x,y,r,c,k,dis):
        if k == 0: return dis
        for dx,dy,dd in d:
            nx = x + dx
            ny = y + dy
            nk = k - 1
            ndis = dis + dd
            if nx < 0 or nx >= n or ny < 0 or ny >= m: continue
            if not can_go(nx,ny,r,c,nk): continue
            return go(nx,ny,r,c,nk,ndis)
        return "impossible"

    dis = ""
    return go(x-1,y-1,r-1,c-1,k,dis)