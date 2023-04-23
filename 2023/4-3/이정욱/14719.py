import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

h,w = map(int,input().split())
blocks = list(map(int,input().rstrip().split()))

if w == 1:
    print(0)
else:
    res = 0
    for i in range(1,w-1):
        left = max(blocks[:i])
        right = max(blocks[i+1:])

        height = min(left,right)
        res += max(0,height - blocks[i])
    print(res)
