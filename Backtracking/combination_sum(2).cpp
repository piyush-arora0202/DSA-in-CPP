#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void getallCombination(vector<int>& arr, int idx, int tar,
                           vector<vector<int>> &ans, vector<int>& combin) {
        
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }

        if (idx >= arr.size() || tar < 0) return;

        // TAKE (single)
        combin.push_back(arr[idx]);
        getallCombination(arr, idx + 1, tar - arr[idx], ans, combin);
        combin.pop_back();

        // SKIP duplicates
        int i = idx;
        while (i + 1 < arr.size() && arr[i] == arr[i + 1]) i++;

        // EXCLUDE
        getallCombination(arr, i + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        sort(arr.begin(), arr.end()); // IMPORTANT

        getallCombination(arr, 0, target, ans, combin);

        return ans;
    }
};
