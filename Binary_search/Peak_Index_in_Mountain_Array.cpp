#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int peakIndexInMountainArray(vector<int> A) {
        // edge cases
        if(A.size() == 1) return 0;
        if(A[0] > A[1]) return 0;
        if(A[A.size()-1] > A[A.size()-2]) return A.size()-1;
        // edge cases
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
