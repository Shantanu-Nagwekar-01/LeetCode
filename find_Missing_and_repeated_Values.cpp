#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> hash(n * n, 0); //initializing hash table with 0
        int repeat, miss;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                hash[grid[row][col] - 1]++;//incrementing count of value of grid[i][j]
            }
        }
        for (int i = 0; i < n * n; i++)
        {
            if (hash[i] == 0)
            {
                miss = i + 1;
            }
            if (hash[i] == 2)
            {
                repeat = i + 1;
            }
        }
        return {repeat, miss};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> Grid = {{1, 3}, {2, 2}};
    vector<int> result = sol.findMissingAndRepeatedValues(Grid);
    cout<<"[";
    for (int x : result) {
        cout<<x<<" ";
    }
    cout<<"]"<<endl;
}
