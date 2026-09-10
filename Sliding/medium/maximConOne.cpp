#include<bits/stdc++.h>
using namespace std;

int longestOnes_Better(vector<int>& nums, int k) {
        int l =0;
        int r =0;
        int maxi =0;
        int zero=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zero++;
            }
            if(zero<=k){
                int len = r-l+1;
                maxi = max(maxi,len);
            }else{
                while(zero>k){
                    if(nums[l]==0) zero--;
                    l++;
                }
            }
            r++;
        }
        return maxi;
        
    }

int longestOnes(vector<int>& nums, int k) {
        int l =0;
        int r =0;
        int maxi =0;
        int zero=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zero++;
            }
            if(zero<=k){
                int len = r-l+1;
                maxi = max(maxi,len);
            }else{
                
                    if(nums[l]==0) zero--;
                    l++;
                
            }
            r++;
        }
        return maxi;
        
    }

int main(){
    vector<int> n = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int k =3;
    cout << " Maximum Number Of Consecutive Ones : " << longestOnes(n,k)<< endl;
    cout << " Maximum Number Of Consecutive Ones : " << longestOnes_Better(n,k)<< endl;
    return 0;
}