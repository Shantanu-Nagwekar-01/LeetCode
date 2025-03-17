class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i + 1])
            {
                return false;
            }
        }
        return true;
        // Alternate Method:
        //    unordered_set<int>OddSet;
        //    for (int x : nums) {
        //         if (OddSet.count(x)) {
        //             OddSet.erase(x);
        //         }
        //         else {
        //             OddSet.insert(x);
        //         }
        //    }
        //    return OddSet.empty();
    }
};