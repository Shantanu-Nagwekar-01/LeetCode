class UnionFind
{
public:
    vector<int> parent, Size, E; // Parent array, Size array, and Edge count array

    // Constructor: Initialize each node as its own parent and size = 1
    UnionFind(int n) : parent(n), Size(n, 1), E(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int FindParent(int x)
    {
        if (x != parent[x])
        {
            parent[x] = FindParent(parent[x]); // Path compression for efficiency
        }
        return parent[x];
    }

    // Union function with union by size
    void Union(int u, int v)
    {
        u = FindParent(u);
        v = FindParent(v);

        if (u != v)
        {
            if (Size[u] < Size[v])
            {
                swap(u, v); // Ensure the larger component remains the root
            }
            parent[v] = u;
            Size[u] += Size[v]; // Update size of the new root
            E[u] += E[v] + 1;   // Merge edge counts and add the new edge
        }
        else
        {
            E[u]++; // If already in the same component, just increment edge count
        }
    }
};

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        UnionFind uf(n);
        unordered_set<int> UniqueRoots; // Stores unique roots of components
        int count = 0;

        // Process all edges and merge nodes into components
        for (vector<int> edge : edges)
        {
            uf.Union(edge[0], edge[1]);
        }

        // Identify unique root nodes after merging components
        for (int i = 0; i < n; i++)
        {
            UniqueRoots.insert(uf.FindParent(i));
        }

        // Count complete components
        for (int root : UniqueRoots)
        {
            int edge = uf.E[root];    // Total edges in this component
            int Size = uf.Size[root]; // Number of nodes in this component

            // A complete component must have exactly Size * (Size - 1) / 2 edges
            if (edge == (Size * (Size - 1)) / 2)
            {
                count++;
            }
        }
        return count;
    }
};

/*
Time Complexity Analysis (TC):
- Union-Find Initialization: O(N)
- Path Compression in Find: Nearly O(1) (amortized)
- Union Operations: O(α(N)) per call, where α is the inverse Ackermann function
- Processing E edges: O(E α(N))
- Finding Unique Roots: O(N)
- Checking Complete Components: O(N)

Overall, the time complexity is **O(N + E α(N))**, which is almost linear.

Space Complexity Analysis (SC):
- Parent, Size, and Edge arrays: O(N)
- Unordered Set for unique roots: O(N)
- Overall Space Complexity: **O(N)**
*/
