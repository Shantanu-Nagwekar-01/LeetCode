#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    vector<int> parent, Size;

    UnionFind(int n) : parent(n), Size(n, 1)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int x)
    {
        if (x != parent[x])
            parent[x] = Find(parent[x]); // Path compression
        return parent[x];
    }

    void Union(int x, int y)
    {
        x = Find(x);
        y = Find(y);
        if (x != y)
        {
            if (Size[x] < Size[y])
                swap(x, y);
            parent[y] = x;
            Size[x] += Size[y];
        }
    }
};

class Solution
{
public:
    int intersect(vector<int> &a, vector<int> &b)
    {
        int i = 0, j = 0, cnt = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                cnt++;
                i++;
                j++;
            }
            else if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return cnt;
        // unordered_set<int> setA(a.begin(), a.end());
        // unordered_set<int> setB(b.begin(), b.end());

        // int count = 0;
        // for (int num : setA) { // Only iterate over distinct elements
        //     if (setB.count(num)) count++;
        // }
        // return count;
    }

    int numberOfComponents(vector<vector<int>> &properties, int k)
    {
        int n = properties.size();
        UnionFind uf(n);
        unordered_set<int> uniqueRoots;
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; i++)
        {
            sort(properties[i].begin(), properties[i].end());
            properties[i].resize(
                unique(properties[i].begin(),
                       properties[i].end()) -
                properties[i].begin()); // unique function stores unique numbers at beginning and duplicate at the end, resize will resize the
            // vector to contain only required unique elements
        }

        // Find valid edges based on intersection condition
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (intersect(properties[i], properties[j]) >= k)
                {
                    edges.emplace_back(i, j); // similar to push_back but faster as it does not copies vector again
                }
            }
        }

        // Perform union operations
        for (auto &edge : edges)
        {
            uf.Union(edge.first, edge.second);
        }

        // Count unique components
        for (int i = 0; i < n; i++)
        {
            uniqueRoots.insert(uf.Find(i));
        }

        return uniqueRoots.size();
    }
};
