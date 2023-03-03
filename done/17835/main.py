import sys
from queue import PriorityQueue

N, M, K = map(int, sys.stdin.readline().rstrip().split())

graph : list[dict[int, int]] = [{} for _ in range(0, N + 1)]

for i in range(0, M):
    U, V, C = map(int, sys.stdin.readline().rstrip().split())
    if U not in graph[V]:
        graph[V][U] = C
    else:
        graph[V][U] = max(graph[V][U], C)

dest : list[int] = list(map(int, sys.stdin.readline().rstrip().split()))

for i in dest:
    graph[0][i] = 0

def dijk(graph : list[dict[int, int]], start : int) -> tuple[int, int]:
    dist : list[int] = [sys.maxsize for _ in range(0, N + 1)]
    Q : PriorityQueue[tuple[int, int]] = PriorityQueue() #tuple[weight, node_no]

    Q.put((0, start))
    
    while not Q.empty():
        weight, from_no = Q.get()
        if dist[from_no] <= weight:
            continue
        dist[from_no] = weight
        for i in graph[from_no]:
            cost = graph[from_no][i]
            Q.put((weight + cost, i))

    return (dist.index(max(dist)), max(dist))

ans_no, ans_index = dijk(graph, 0)

print(ans_no)
print(ans_index)
