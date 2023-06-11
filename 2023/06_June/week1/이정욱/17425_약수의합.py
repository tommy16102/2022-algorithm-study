import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

t = int(input())

fx = [0 for _ in range(1000000+1)]
gx = [0]

for i in range(1, 1000000+1):
    for j in range(i, 1000000+1, i):
        fx[j] += i

for e in fx:
    gx.append(gx[-1]+e)
    
for _ in range(t):
    n = int(input())
    print(gx[n+1])
