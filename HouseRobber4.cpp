class Solution
{
public:
    bool check(vector<int> &nums, int k, int guess)
    {
        int i = 0, N = nums.size();
        while (i < N)
        {
            if (nums[i] <= guess)
            {
                k--;
                i += 2;
                if (k == 0)
                {
                    return true;
                }
            }
            else
            {
                i += 1;
            }
        }
        return false;
    }
    int minCapability(vector<int> &nums, int k)
    {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int Min_cap = 0, mid;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (check(nums, k, mid))
            {
                Min_cap = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return Min_cap;
    }
};