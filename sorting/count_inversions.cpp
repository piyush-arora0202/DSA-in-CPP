// Count Inversions // 
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>&arr,int st ,int mid ,  int end) {
    vector<int>temp;
    int invCount = 0;
    int i = st, j = mid + 1;
    // merge both halves
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            invCount += (mid - i + 1);
            j++;
        }
    }

    // remaining elements (LEFT)
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // remaining elements (RIGHT)
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }
    return invCount;
}

int mergesort(vector<int>&arr,int st , int end) {
    if (st<end) {
        int mid = st + (end-st)/2;

        int leftinvCount = mergesort(arr,st,mid);
        int rightinvCount = mergesort(arr,mid+1,end);
        int invCount = merge(arr,st,mid,end);

        return leftinvCount + rightinvCount + invCount;
    }
    return 0;
}

int main() {
    vector<int>arr = {6,3,5,2,7};
    int ans = mergesort(arr,0,arr.size() -1);
    cout << "Inv count: " << ans << endl; 
    return  0;
}