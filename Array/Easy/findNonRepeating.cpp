#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

*/

int singleNumber_better(vector<int>& v) {
        int n = v.size();
        map <int ,int> mpp;
        for(int i=0;i<n;i++){
            mpp[v[i]]++;
        }
        for(auto a : mpp){
            if(a.second == 1){
                return a.first;
            }
        }

        return -1;
        
    }
    
int singleNumber(vector<int>& v) {
        int n = v.size();
       int ans=0;
        for(int i=0;i<n;i++){
            ans^=v[i];
        }

        return ans;
        
    }

int main (){
    vector <int> v = {4,1,2,1,2};

    int ans = singleNumber(v);
    // int ans = singleNumber_better(v);

    cout<< " not reapeatig : "<< ans << endl;

    return 0;
}