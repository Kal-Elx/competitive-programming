import sys
import math


class Node():
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.tree = UnionFindElem(self)


class Edge():
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.dist = math.sqrt((a.x - b.x)**2 + (a.y - b.y)**2)

    def union(self):
        return self.a.tree.union(self.b.tree)


class UnionFindElem():
    def __init__(self, edge):
        self.edge = edge
        self.parent = None
    
    def union(self, other):
        self_root = self.find()
        other_root = other.find()

        if (self_root == other_root):
            return False

        self_root.parent = other_root
        return True

    def find(self):
        curr = self
        while curr.parent != None:
            curr = curr.parent
        return curr
        
        
def kruskal(graph):
    res = 0
    for edge in graph:
        if edge.union():
            res += edge.dist
    return res


tc = int(sys.stdin.readline())

for i in range(tc):
    sys.stdin.readline() # Ignore blank line.
    n = int(sys.stdin.readline())

    points = []
    for j in range(n):
        x, y = sys.stdin.readline().split()
        points.append(Node(float(x), float(y)))

    graph = []
    for j in range(n):
        for k in range(j + 1, n):
            graph.append(Edge(points[j], points[k]))

    graph.sort(key=lambda edge: edge.dist)
    
    print("{:.2f}{}".format(kruskal(graph), "\n" if i + 1 < tc else ""))
