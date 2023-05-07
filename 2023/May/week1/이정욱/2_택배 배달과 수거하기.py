def solution(cap, n, deliveries, pickups):
    answer = 0
    
    deliveries = deliveries[::-1]
    pickups = pickups[::-1]
    
    d = 0
    p = 0
    
    for i in range(n):
        d += deliveries[i]
        p += pickups[i]
        
        while d > 0 or p > 0:
            d -= cap
            p -= cap
            answer += (n-i)*2
    return answer