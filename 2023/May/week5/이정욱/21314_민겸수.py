import sys
import re
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

_s = input().rstrip()

def get_MK_num(s):
    return  "5" + "0" * (len(s)-1)

def applyMK(s):
    regex = "[M]+K"
    _list = re.compile(regex).findall(s)
    sub = list(re.sub(regex,"*",s))
    idx = 0

    for i in range(len(sub)):
        if sub[i] == "*":
            sub[i] = get_MK_num(_list[idx])
            idx += 1
    return sub

def get_MM_num(s):
    return "1" + "0" * (len(s)-1)

def applyMM(s):
    regex = "M[M]+"
    _list = re.compile(regex).findall(s)
    sub = list(re.sub(regex,"*",s))
    idx = 0

    for i in range(len(sub)):
        if sub[i] == "*":
            sub[i] = get_MM_num(_list[idx])
            idx += 1
    return sub

def go(l):
    for i in range(len(l)):
        if l[i] == "M":
            l[i] = "1"
        if l[i] == "K":
            l[i] = "5"
    return "".join(l)

big = applyMK(_s)
small = applyMM(_s)

print(go(big))
print(go(small))