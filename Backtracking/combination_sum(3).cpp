#include <vector>
using namespace std;
class Solution {
public:
    void solve(int num,int k,int tar,vector<vector<int>>& ans,vector<int>&combin) {
        if (k==0 && tar==0) {
            ans.push_back(combin);
            return;
        }
        if (num > 9 || k<0 || tar < 0) {
            return;
        }
        // take 
        combin.push_back(num);
        solve(num+1,k-1,tar-num,ans,combin);
        combin.pop_back();

        solve(num+1,k,tar,ans,combin);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combin;

        solve(1, k, n, ans,combin); // start from 1
        return ans;
        
    }
};