// Approach: Two Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int maxWater = 0;
    int lp = 0;
    int rp = height.size() - 1;

    while (lp < rp) {
        int width = rp - lp;
        int ht = min(height[lp], height[rp]);
        int area = width * ht;

        maxWater = max(maxWater, area);

        // Move the pointer with smaller height
        if (height[lp] < height[rp]) {
            lp++;
        } else {
            rp--;
        }
    }
    return maxWater;
}
int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum water that can be stored: "
         << maxArea(height) << endl;

    return 0;
}
