class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        // int start = 0, end = nums.size() - 1;
        int N = nums.size(), count = 0;
        vector<int> lower;
        vector<int> higher;
        for (int i : nums)
        {
            if (i < pivot)
            {
                lower.push_back(i);
            }
            else if (i > pivot)
            {
                higher.push_back(i);
            }
            else
            {
                count++; // to store pivots count
            }
        }
        int i = 0, j = 0, l = lower.size(), h = higher.size();
        while (i < l)
        {
            nums[i] = lower[i];
            i++;
        }
        while (count--)
        {
            nums[i] = pivot;
            i++;
        }
        while (j < h)
        {
            nums[i] = higher[j];
            i++;
            j++;
        }
        return nums;
    }
};