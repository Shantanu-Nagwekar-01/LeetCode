class UnionFind():
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
    
    def FindParent(self, x):
        if (x!=self.parent[x]):
            self.parent[x] = self.FindParent(self.parent[x])
        return self.parent[x]
    
    def Union(self, x, y):
        x = self.FindParent(x)
        y = self.FindParent(y)
        if (x != y):
            if self.size[x] < self.size[y]:
                self.parent[x] = y
                self.size[y] += self.size[x]
            else:
                self.parent[y] = x
                self.size[x] += self.size[y]

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        uf = UnionFind(n)

        #initialize connected components of graph

        for u, v in edges:
            uf.Union(u, v)

        root_src = uf.FindParent(source)
        root_dest = uf.FindParent(destination)

        #check whether the soirce and destination nodes have same ultimate parent
        #if yes return true else false
        if root_src != root_dest:
            return False
        else:
            return True