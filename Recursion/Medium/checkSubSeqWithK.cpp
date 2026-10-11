#include<bits/stdc++.h>
using namespace std;


    bool subseq(vector<int>& nums,int idx,int sum, int k){
        
        if(idx == nums.size()){
            return k== sum;
        }
        // ignore
        if(subseq(nums,idx+1,sum,k)){
            return true;
        }

        // add
        if(subseq(nums,idx+1,sum+nums[idx],k)){
            return true;
        }
        return false;

    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
       return subseq(nums,0,0,k);
    }

    int main(){
        vector<int> nums ={1,2,3};
        cout << checkSubsequenceSum(nums,6) << endl;

        return 0;
    }