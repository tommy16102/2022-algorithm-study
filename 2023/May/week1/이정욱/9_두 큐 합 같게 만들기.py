from collections import deque

def solution(queue1, queue2):
    q1 = deque(queue1)
    q2 = deque(queue2)
    s1 = sum(queue1)
    s2 = sum(queue2)
    
    max_cnt = 10000000
    cnt = 0
    
    while 1:
        if s1 == s2:
            return cnt
        
        if cnt > max_cnt:
            return -1
        
        if s1 > s2:
            p = q1.popleft()
            q2.append(p)
            s1 -= p
            s2 += p
        else:
            p = q2.popleft()
            q1.append(p)
            s2 -= p
            s1 += p
        cnt += 1
    
    return -1