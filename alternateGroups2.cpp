class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int N = colors.size();
        int left = 0;
        int count = 0;
        for (int right = 1; right < (N + k - 1); right++)
        {
            if (colors[right % N] == colors[(right - 1) % N])
            {
                left = right;
            }
            if ((right - left + 1) > k)
            {
                left++;
            }
            if ((right - left + 1) == k)
            {
                count++;
            }
        }
        return count;
    }
};