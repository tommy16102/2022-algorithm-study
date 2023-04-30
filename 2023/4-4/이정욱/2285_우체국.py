import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
arr = []
arr_sum = []
_sum = 0
current = 0

for _ in range(n):
    a,b = map(int,input().split())
    arr.append([a,b])

arr.sort()
# print(arr)

for i in range(n):
    a,b = arr[i]
    arr.append(b)
    current += i*b
    _sum += b
    arr_sum.append(_sum)

res = [current, arr[0][0]]
def get_sum(start,end):
    if start == 0:
        return arr_sum[end]
    else:
        return arr_sum[end] - arr_sum[start-1]

for i in range(1,n):
    current += get_sum(0,i-1)
    current -= get_sum(i,n-1)
    if res[0] > current:
        # print(f"current: {current}, i: {i}")
        res[0] = current
        res[1] = arr[i][0]
print(res[1])