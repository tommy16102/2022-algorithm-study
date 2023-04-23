import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,k = map(int,input().split())
arr = list(map(int,input().split()))
seq = []
apps = {}

for i in range(len(arr)):
    e = arr[i]
    if e in apps: 
        seq.append(apps[e])
        continue
    apps[e] = [0,e]
    seq.append(apps[e])

multi = {}
multi_set = set()
res = 0

def plug_in(idx):
    multi[idx] = seq[idx][1]
    multi_set.add(multi[idx])
    seq[idx][0] = 1
    return

def plug_out(idx):
    global res
    res += 1
    multi_set.discard(multi[idx])
    del multi[idx]
    seq[idx][0] = 0
    return

for i in range(len(seq)):
    if seq[i][0] == 1: continue
    if len(multi) < n:
        plug_in(i)
        continue
    
    remain = seq[i+1:]
    
    for e in multi:
        is_in = False
        for j in range(len(remain)):
            if multi[e] == remain[j][1]:
                is_in = True
                break
        if not is_in:
            plug_out(e)
            break
    
    if len(multi) == n:
        can = []
        can_set = set()
        for j in range(len(remain)):
            if remain[j][1] in multi_set:
                can.append(j)
                if remain[j][1] not in can_set:
                    can_set.add(remain[j][1])
            if len(can_set) == n:
                break

        for e in multi:
            if multi[e] == remain[can[-1]][1]:
                k = e
                break
        plug_out(k)

    plug_in(i)

print(res)