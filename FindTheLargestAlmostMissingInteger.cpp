class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        int left = 0, right = k - 1;
        int N = nums.size();
        int Max = -1;

        if (k == N)
        {
            for (int i = 0; i < N; i++)
            {
                Max = (nums[i] >= Max) ? nums[i] : Max;
            }
            return Max;
        }
        while (right < N)
        {
            for (int i = left; i <= right; i++)
            {
                hash[nums[i]]++;
            }
            left++;
            right++;
        }
        for (int i = 0; i < N; i++)
        {
            if (hash[nums[i]] == 1)
            {
                Max = (nums[i] >= Max) ? nums[i] : Max;
            }
        }
        return Max;
    }
};