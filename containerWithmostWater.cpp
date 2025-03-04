#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int start = 0;
            int end = height.size() - 1;
            int max_area = 0;
            int area;
            while (start < end) {
                // Comparing heights of two endpoints and moving the pointer that has the smaller height
                if (height[start] <= height[end]) {
                    area = height[start] * (end - start);
                    start++; // incrementing the start the pointer when the height pointed by it previously is small
                }
                else {
                    area = height[end] * (end - start);
                    end--; // decrementing the end pointer when the height pointed by it previously is small
                }
                max_area = max(max_area, area);
            }
            return max_area;
        }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout<<sol.maxArea(height);

}

