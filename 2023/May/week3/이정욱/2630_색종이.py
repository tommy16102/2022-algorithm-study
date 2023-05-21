import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]


def check(x,y,size):
    for i in range(x,x+size):
        for j in range(y,y+size):
            if arr[x][y] != arr[i][j]:
                return -1
    return arr[x][y]

white = 0
blue = 0

def go(x,y,size):
    global white
    global blue
    
    res = check(x,y,size)
    if res == 0:
        white += 1
    elif res == 1:
        blue += 1
    else:
        n_size = size // 2
        go(x,y,n_size)
        go(x,y+n_size, n_size)
        go(x+n_size,y, n_size)
        go(x+n_size,y+n_size, n_size)
    return

go(0,0,n)

print(white)
print(blue)