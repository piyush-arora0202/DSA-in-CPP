#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    set<vector<int>>s;
    void getallCombination(vector<int>& arr,int idx , int tar , vector<vector<int>> &ans,vector<int>&combin) {
        if (idx == arr.size() || tar<0) {
            return;
        }
        if (tar==0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }


        combin.push_back(arr[idx]);
        //single
        getallCombination(arr,idx+1,tar-arr[idx],ans,combin) ;
        //multiple
        getallCombination(arr,idx,tar-arr[idx],ans,combin);
        // exclusion
        combin.pop_back();
        getallCombination(arr,idx+1,tar,ans,combin);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>combin;

        getallCombination(arr,0,target,ans,combin);

        return ans;
    }
};