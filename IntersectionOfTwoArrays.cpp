#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> result;
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                result.insert(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        for (int x : result)
        {
            res.push_back(x);
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2}, ans;
    ans = sol.intersection(nums1, nums2);
    cout << "[";
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << ']';
    return 0;
}