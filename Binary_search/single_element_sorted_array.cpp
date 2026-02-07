#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if (n == 1) return A[0];

        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // boundary cases
            if (mid == 0 && A[0] != A[1]) return A[0];
            if (mid == n-1 && A[n-1] != A[n-2]) return A[n-1];
            // check if mid itself is single
            if (A[mid-1] != A[mid] && A[mid] != A[mid+1]) return A[mid];

            if (mid % 2 == 0) { // even index
                if (A[mid] == A[mid+1])
                    st = mid + 1;   // ✅ SAME AS YOUR SCREENSHOT
                else
                    end = mid - 1;
            } 
            else { // odd index
                if (A[mid] == A[mid-1])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};
int main() {
    Solution s;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Error: Array size must be ODD.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter sorted array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = s.singleNonDuplicate(arr);
    cout << "Single element is: " << ans << endl;

    return 0;
}