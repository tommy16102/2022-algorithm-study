import sys
from itertools import combinations
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n,m = map(int, input().split())
member = [[] for _ in range(54)]
member_visited = [0 for _ in range(54)]
party = [[] for _ in range(54)]
party_visited = [0 for _ in range(54)]

knowns = list(map(int, input().split()))
knowns = knowns[1:]

# 진실을 아는 사람과 같은 파티에 왔던 사람이 있는 파티에서는 진실을 말한다
def go_party(here_party):
    party_visited[here_party] = 1
    for e in party[here_party]:
        if member_visited[e]: continue
        go_member(e)

def go_member(here_member):
    member_visited[here_member] = 1
    for e in member[here_member]:
        if party_visited[e]: continue
        go_party(e)


for i in range(m):
    come = list(map(int,input().split()))
    come = come[1:]
    party[i] = come
    for e in come:
        member[e].append(i)

for e in knowns:
    go_member(e)

print(m - sum(party_visited))