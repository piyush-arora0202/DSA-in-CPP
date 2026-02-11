// Approach: Three pointers
// Time: O(n)
// Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++; mid++;
            } 
            else if (nums[mid] == 1) {
                mid++;
            } 
            else { // 2
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

int main() {
    vector<int> arr = {2,0,1,2,1,0,0,2,1};

    Solution s;
    s.sortColors(arr);

    for(int x : arr) cout << x << " ";
    return 0;
}