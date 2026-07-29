#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<unordered_map>
#include <climits>
using namespace std;

vector<int> majorityElement_better(vector<int> &v){
    int n = v.size();
    vector<int> ans;
    int minm=(int)n/3;
    unordered_map <int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
        if(mpp[v[i]]== minm +1){
            ans.push_back(v[i]);
        }
    }
    sort(ans.begin() , ans.end());
    return ans;

}

vector<int> majorityElement(vector<int> &v){
    int n = v.size();
    vector<int> ans;
    int minm=(int)n/3;
    int el1= INT_MIN;
    int el2 = INT_MIN;
    int cnt1 =0;int cnt2 =0;

    for(int i=0;i<n;i++){
       if(cnt1==0 && v[i]!=el2){
        cnt1=1;
        el1=v[i];

       }else if(cnt2==0 && v[i]!=el1){
            cnt2=1;
            el2=v[i];
       }else if(v[i]==el1){
        cnt1++;
       }else if(v[i]==el2){
        cnt2++;
       }else{
        cnt1--;
        cnt2--;
       }
    }
  
    int count1=0;
    int count2=0;

    for(int i=0;i<n;i++){
        if(v[i]==el1){
            count1++;
        }else if(v[i]==el2){
            count2++;
        }
    }
    if(count1>minm){
        ans.push_back(el1);
        
    }
    if(count2>minm){
        ans.push_back(el2);
    }
    sort(ans.begin() , ans.end());
    return ans;

}




int main (){

    vector <int> v = {1,2,1,2,3,1,3,3};
    // vector <int> ans = majorityElement_better(v);
    vector <int> ans = majorityElement(v);
    cout<< "Majority n/3  "<< endl;
    for(auto a : ans){
        cout << a << ", ";
    }




    return 0;
}