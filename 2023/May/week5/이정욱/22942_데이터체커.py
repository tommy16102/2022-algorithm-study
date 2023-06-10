# 답 봤습니다......
import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
circles = []

for i in range(n):
    x,r = map(int,input().split())
    circles.append((x-r,i))
    circles.append((x+r,i))
circles.sort()

st = []

for x,i in circles:
    if st and st[-1] == i:
        st.pop()
    else:
        st.append(i)

if not st: print("YES")
else: print("NO")