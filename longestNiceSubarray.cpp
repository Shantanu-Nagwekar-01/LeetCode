class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int cur = 0; // cur is bitmask
        int best = 0, count = 0, left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            while (cur & nums[right])
            {
                cur ^= nums[left++]; // unset the overlapping bits ->  1 ^ 1 = 0 and n ^ 0 = n
            }
            best = max(best, right - left + 1);
            cur |= nums[right]; // set the non-overlaping bits -> 1 | 0 = 1
        }
        return best;
    }
};