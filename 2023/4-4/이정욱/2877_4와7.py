import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

k = int(input())

here = 2
cnt = 2
seq = [2]
seq_cnt = [2]

while cnt < k:
    here *= 2
    cnt += here
    seq.append(here)
    seq_cnt.append(cnt)

# print(seq)
# print(seq_cnt)

res = ""

for i in range(len(seq)-1,0,-1):
    half = seq[i] / 2
    if k - seq_cnt[i-1] <= half:
        res += "4"
        k -= half
    else:
        res += "7"
        k -= seq[i]

if k % 2 == 0:
    res += "7"
else:
    res += "4"
print(res)