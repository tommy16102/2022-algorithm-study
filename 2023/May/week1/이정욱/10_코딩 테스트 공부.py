import heapq

def solution(alp, cop, problems):
    answer = 0
    max_alp = 0
    max_cop = 0
    real_problems = [[0,0,0,1,1],[0,0,1,0,1]]
    for e in problems:
        max_alp = max(max_alp,e[0])
        max_cop = max(max_cop,e[1])
        if e[2]+e[3] > e[4]: real_problems.append(e)
    
    visited = [[1e10 for _ in range(151)] for _ in range(151)]
    visited[alp][cop] = 0
    
    pq = []
    heapq.heappush(pq,[0,alp,cop])
    
    while pq:
        h,a,c = heapq.heappop(pq)
        dd = [(1,0,1),(0,1,1)]
        if a == max_alp and c == max_cop: break
        
        for aa,cc,da,dc,dh in real_problems:
            if aa > a or cc > c: continue
            na = a + da
            nc = c + dc
            nh = h + dh
            na = min(na, max_alp)
            nc = min(nc, max_cop)
            if visited[na][nc] > nh:
                visited[na][nc] = nh
                heapq.heappush(pq,[nh,na,nc])
    
    return visited[max_alp][max_cop]