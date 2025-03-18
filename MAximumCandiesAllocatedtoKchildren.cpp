class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long best = 0;
        int N = candies.size();
        long long left = 1;
        long long mid, count, sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += candies[i];
        }
        long long right = sum / k;
        while (left <= right)
        {
            count = 0;
            mid = left + (right - left) / 2;
            for (int x : candies)
            {
                count += x / mid;
            }
            if (count >= k)
            {
                best = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return best;
    }
};