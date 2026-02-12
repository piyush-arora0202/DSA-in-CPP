#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: Next Permutation
// Approach: Breakpoint + swap + reverse suffix
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& A) {

        int n = A.size();
        int pivot = -1;

        // Step 1: find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot, reverse whole array
        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 2: find next greater element and swap
        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // Step 3: reverse suffix
        int i = pivot + 1, j = n - 1;
        while (i <= j) {
            swap(A[i++], A[j--]);
        }
    }
};

int main() {
    vector<int> arr = {1, 2, 3};

    Solution s;
    s.nextPermutation(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}
