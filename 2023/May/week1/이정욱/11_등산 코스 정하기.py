

import sys
import heapq
sys.setrecursionlimit(10 ** 5)

def solution(n, paths, gates, summits):
    answer = []
    graph = [[] for _ in range(n+1)]
    is_summit = [0 for _ in range(n+1)]
    
    for i in range(len(paths)):
        f,t,d = paths[i]
        graph[f].append([d,t])
        graph[t].append([d,f])
        
    for e in summits:
        is_summit[e] = 1
    
    def go():
        dist = [1e10 for i in range(n+1)]
        pq = []
        for e in gates:
            dist[e] = 0
            heapq.heappush(pq,[0,e])
        
        while pq:
            here_dist,here = heapq.heappop(pq)
            if is_summit[here]: 
                answer.append([here_dist,here])
                continue
            if dist[here] != here_dist: continue
            for i in range(len(graph[here])):
                d,next = graph[here][i]
                if dist[next] > max(dist[here],d):
                    dist[next] = max(dist[here],d)
                    heapq.heappush(pq,[dist[next],next])
        return
    
    go()
    answer.sort()
    return [answer[0][1],answer[0][0]]