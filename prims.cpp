
def prim(graph, start):
    visited = {start}
    mst = []
    total = 0

    while len(visited) < len(graph):
        edge = min(
            (w, u, v)
            for u in visited
            for v, w in graph[u].items()
            if v not in visited
        )
        w, u, v = edge
        mst.append((u, v, w))
        total += w
        visited.add(v)

    print("Edges in MST:", mst)
    print("Total Cost:", total)


n = int(input("Enter number of vertices: "))
graph = {}

for i in range(n):
    vertex = input("Enter vertex name: ")
    graph[vertex] = {}

m = int(input("Enter number of edges: "))

for i in range(m):
    u, v, w = input("Enter edge (u v weight): ").split()
    w = int(w)
    graph[u][v] = w
    graph[v][u] = w

start = input("Enter starting vertex: ")
prim(graph, start)
