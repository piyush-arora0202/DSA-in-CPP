#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int peakIndexInMountainArray(vector<int> A) {
        int st = 1 , end = A.size() - 2;

        while (st <= end) {
            int mid = st + (end-st) / 2;

            if (A[mid-1] < A[mid] && A[mid] > A[mid+1]) {
                return mid;
            } 
            else if (A[mid-1] < A[mid]) { // go right
                st = mid + 1;
            } 
            else {  // go left
                end = mid - 1;
            }
        }
        return -1;
    }    
};

int main() {
    Solution s;

    vector<int> arr = {1, 3, 5, 7, 6, 4, 2};

    int ans = s.peakIndexInMountainArray(arr);

    cout << "Peak index = " << ans << endl;

    return 0;
}
