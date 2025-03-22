class Solution
{
public:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> adj;
    void dfs(int v, vector<int> &res)
    {
        if (visited.find(v) != visited.end())
        {
            return;
        }
        visited.insert(v);
        res.push_back(v);
        for (int i = 0; i < adj[v].size(); i++)
        {
            dfs(adj[v][i], res);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        visited.clear();
        adj.clear();
        for (vector<int> edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        for (int v = 0; v < n; v++)
        {
            if (visited.find(v) != visited.end())
            {
                continue;
            }
            vector<int> component;
            dfs(v, component);
            bool isCompleteComponent = true;
            for (int u : component)
            {
                if (adj[u].size() != component.size() - 1)
                {
                    isCompleteComponent = false;
                    break;
                }
            }
            if (isCompleteComponent)
            {
                count++;
            }
        }
        return count;
    }
};