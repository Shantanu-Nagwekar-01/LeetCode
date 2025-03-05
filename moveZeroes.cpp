#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int  zptr = 0; //initializing the pointer that points to first zero in nums array
            while (zptr < nums.size() && nums[zptr] != 0) {
                    zptr++;
                }
                //initializing the number pointer that iterates through entire array just next to zero pointer so zptr + 1
            for (int nptr = zptr + 1; nptr < nums.size(); nptr++) {
                if (nums[nptr]) {
                    swap(nums[zptr], nums[nptr]);
                    zptr++;// incrementing or moving the zero pointer only when swap of numbers happen
                }
    
            }
        }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    cout<<"[";
    for (int x : nums) {
        cout<<x<<" ";
    }
    cout<<"]";
}