import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,k = map(int,input().split())
arr = list(map(int,input().split()))

l = 0
r = 0
cnt = 0
if arr[l]%2 == 1: cnt = 1
res = 0

while 1:
    # print(f"l:{l}, r:{r} => cnt:{cnt}, res:{res}")
    res = max(res,(r-l+1)-cnt)
    if r == n-1: break
    if cnt <= k:
        r += 1
        if arr[r]%2 == 1: cnt += 1
    else:
        if arr[l]%2 == 1: cnt -= 1
        l += 1

print(res)    

    
