class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int majority = 0, c = 0, left_cnt = 0, right_cnt, llen, rlen, len = nums.size();
        for (int n : nums)
        {
            if (c == 0)
            {
                majority = n;
            }
            if (majority == n)
            {
                c++;
            }
            else
            {
                c--;
            }
        }
        right_cnt = count(nums.begin(), nums.end(), majority);
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == majority)
            {
                left_cnt++;
                right_cnt--;
            }

            llen = i + 1;
            rlen = len - i - 1;

            if (2 * left_cnt > llen && 2 * right_cnt > rlen)
            {
                return i;
            }
        }
        return -1;
    }
};