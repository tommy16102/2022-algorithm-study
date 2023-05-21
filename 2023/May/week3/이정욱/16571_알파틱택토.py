import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

first, second = 0, 0
m = [list(map(int,input().split())) for _ in range(3)]

for i in range(3):
    for j in range(3):
        if m[i][j] == 1:
            first += 1
        elif m[i][j] == 2:
            second += 1
 
def check(m, turn):
    prev_turn = 1 if turn == 2 else 2
    if (m[0][0] == m[1][1] == m[2][2] == prev_turn) or (m[0][2] == m[1][1] == m[2][0] == prev_turn):
        return True
    for i in range(3):
        if (m[i][0] == m[i][1] == m[i][2] == prev_turn) or (m[0][i] == m[1][i] == m[2][i] == prev_turn):
            return True
    return False
 
def go(m, turn):
    if turn == 3:
        turn = 1
    mn = 2
    if check(m, turn):
        return -1
 
    for i in range(3):
        for j in range(3):
            if m[i][j] == 0:
                m[i][j] = turn
                mn = min(mn, go(m, turn+1))
                m[i][j] = 0
 
    if mn == 1:
        return -1
    elif mn == 2 or mn == 0:
        return 0
    else:
        return 1
 
if first == second:
    start = 1
else:
    start = 2

res = go(m, start)
if res == 1:
    print('W')
elif res == 0:
    print('D')
else:
    print('L')