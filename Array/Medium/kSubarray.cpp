#include<iostream>
#include<vector>
#include<map>
using namespace std;

int kSubArray_brute(vector<int> &v,int target){
    int n = v.size();
    int count =0;
    for(int i =0;i<n;i++){
        int sum =0;
        for(int j = i;j<n;j++){
            sum+=v[j];
            if(sum == target){
                count++;
            }
        }
    }

    return count;
}

int kSubArray(vector<int> &v,int target){
    map<int,int> mpp;
   int n = v.size();
   mpp[0] =1;
   int pre_sum =0;
    int count =0;
    for(int i =0;i<n;i++){
        pre_sum +=v[i];
        int baki = pre_sum -target;
        count += mpp[baki];
        mpp[baki]+=1;
    }
}

int main(){
    vector<int> v ={2,1,4,3,5,6,4};
    int ans = kSubArray_brute(v,3);
    int ans2 = kSubArray_brute(v,3);
    cout<< " number of subarray " << ans <<endl;
    cout<< " number of subarray " << ans2 <<endl;

    return 0;
}