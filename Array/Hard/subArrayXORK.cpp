#include<iostream>
#include<vector>
#include<map>
using namespace std;

int subarrayXorK_better(vector<int> v,int target){
    int count =0;
    int n = v.size();
    for(int i =0;i<n;i++){
        int xorr = 0;
        for (int j = i; j < n; j++)
        {   xorr= xorr^v[j];
            if(xorr == target){  
                count++;  }
        }
        
    }
    return count;

}

int subArrayk(vector<int> v,int target){
    map<int,int> mpp;
    mpp[0]=1;
    int n = v.size();
    int count =0;
    int pre_xor =0;
    for(int i=0;i<n;i++){
        pre_xor = pre_xor^v[i];
        int first_part = pre_xor^target;
        // int first_part = target^pre_xor;
            count+=mpp[first_part];
        mpp[first_part]++;
    }
    return count;
}

int main(){
    vector<int> v ={4, 2, 2, 6, 4};
    int target =6;
    cout<<"count of target "<< target<<endl;
    cout<< subarrayXorK_better(v,target)<<endl;
    cout<< subArrayk(v,target)<<endl;


    return 0;

}