class DisjointSet():
    def __init__(self,n):
        self.parent = list(range(n))
        self.size = [1] * n
    
    def FindParent(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.FindParent(self.parent[x])
        return self.parent[x]
    
    def Union(self, x, y):
        x = self.FindParent(x)
        y = self.FindParent(y)
        if x != y:
            if self.size[x] < self.size[y]:
                self.parent[x] = y
                self.size[y] += self.size[x]
            else:
                self.parent[y] = x
                self.size[x] += self.size[y]

    
class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        DS = DisjointSet(n)

        for u, v, w in edges:
            DS.Union(u,v)
        
        component_cost = {}

        for u, v, w in edges:
            root = DS.FindParent(u)
            if root not in component_cost:
                component_cost[root] = w
            else:
                component_cost[root] &= w
        
        res = []
         
        for src, dest in query:
            r1, r2 = DS.FindParent(src), DS.FindParent(dest)
            if r1 != r2:
                res.append(-1)
            else:
                res.append(component_cost[r1])
            
        return res
        