#include <bits/stdc++.h>
using namespace std;

int count(vector<int>& nums,int sum ,int idx,int k){
    if(idx == nums.size()){
        if(sum ==k){
            return 1;
        }
        return 0;
    }
    //  ignore
    int ig = count(nums,sum,idx+1,k);

    // add
    sum = sum + nums[idx];
    int ad = count(nums,sum,idx+1,k);

    return ig+ad;
}

int countSubSeqWithK(vector<int>& nums,int k){
    return count(nums,0,0,k);

}




int main(){
    vector<int> nums={4, 9, 2, 5, 1};
    int k =10;

    int ans = countSubSeqWithK(nums,k);

    cout<< ans << endl;

    return 0;
}