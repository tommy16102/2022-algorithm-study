import sys
import heapq
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

_str = input().rstrip()
res = ['' for _ in range(len(_str))]
str_list = []
for i in range(len(_str)):
    str_list.append([i,ord(_str[i])])

def go(s):
    if len(s) == 0: return
    if len(s) == 1:
        res[s[0][0]] = chr(s[0][1])
        print("".join(res))
        return

    _min = 0
    for i in range(len(s)):
        if s[_min][1] > s[i][1]:
            _min = i
    go([s[_min]])
    go(s[_min+1:])
    go(s[:_min])

go(str_list)