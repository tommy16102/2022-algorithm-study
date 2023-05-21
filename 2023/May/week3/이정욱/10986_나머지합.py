import sys
 
n, m = map(int, input().split())
num_list = list(map(int, sys.stdin.readline().rstrip().split()))
 
remainder_info = [0 for _ in range(m)]
remainder_info[0] = 1
 
total = 0
for i in range(n):
    total += num_list[i]
    r = total % m
    # 나머지 값에 따라서 idx 정보 저장
    remainder_info[r] += 1
 
count = 0
for i in remainder_info:
    count += i*(i - 1) // 2
 
print(count)