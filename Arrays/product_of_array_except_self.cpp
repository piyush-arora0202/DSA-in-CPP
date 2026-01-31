// Problem: Product of Array Except Self
// Approach: Prefix product stored in answer array + suffix variable
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding output array)

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    // Prefix product
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    // Suffix product
    int suffix = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);

    cout << "Product of array except self:\n";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
