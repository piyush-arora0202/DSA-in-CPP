// Time Complexity: O(n)
// Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int val : nums) {
        currSum += val;
        maxSum = max(maxSum, currSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
    return 0;
}
// use case is solving the MAXIMUM Subarray problem