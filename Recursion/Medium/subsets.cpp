#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> set,int idx, vector<vector<int>>& ans){
    if(idx>= nums.size()){
        ans.push_back(set);
        return;
    }

    // ignore
    solve(nums,set,idx+1,ans);

    // add
    set.push_back(nums[idx]);
    solve(nums,set,idx+1,ans);
}

vector<vector<int>> subsets(vector<int> nums){
    vector<vector<int>> ans;
    vector<int> set;
    
    solve(nums,set,0,ans);
    return ans;
}
int main(){
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = subsets(nums);

    for(auto it : ans){
       for(auto iit:it){
        cout<<iit<<",";
       }
       cout<<"|";
    }

    return 0;
}