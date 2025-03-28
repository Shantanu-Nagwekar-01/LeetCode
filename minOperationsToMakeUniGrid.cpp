class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> nums;
        int rem = grid[0][0] % x;
        for (vector<int> row : grid)
        {
            for (int a : row)
            {
                if (rem != a % x)
                {
                    return -1;
                }
                nums.push_back(a);
            }
        }
        sort(nums.begin(), nums.end());
        int i = nums.size() / 2;
        int median = nums[i];
        int count = 0;
        for (int a : nums)
        {
            count += abs(a - median) / x;
        }
        return count;
    }
};