import sys
import heapq as hq

N, M = map(int, sys.stdin.readline().rstrip().split())

graph : list[list[tuple[int, int]]] = [[] for _ in range(0, N)] #to, time

for i in range(0, M):
    A, B = map(int, sys.stdin.readline().rstrip().split())
    A -= 1
    B -= 1
    graph[A].append((B, i))
    graph[B].append((A, i))

def dijk(graph : list[list[tuple[int, int]]], N, M, s_pos) -> int: #return time
    visited : list[bool] = [False for _ in range(0, N)]
    Q : list[tuple[int, int]] = []
    hq.heapify(Q)

    hq.heappush(Q, (0, s_pos))

    while Q:
        weight, from_pos = hq.heappop(Q)

        if visited[from_pos]:
            continue
        visited[from_pos] = True
        
        if from_pos == (N - 1):
            return weight

        for i in graph[from_pos]:
            to, time = i
            cost = time - (weight % M)

            if(cost < 0):
                cost += M
            hq.heappush(Q, (weight + cost + 1, to))

    return -1

print(dijk(graph, N, M, 0))
