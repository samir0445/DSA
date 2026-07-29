#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leaderInArray_brute(vector<int> v){
    vector<int> ans;
    int n= v.size();
    for(int i=0;i<n;i++){
        bool isLeader = true;
        for(int j=i+1;j<n;j++){
            if(v[j]>v[i]){
                isLeader = false;
                break;
            }
        }
        if(isLeader == true){
            ans.push_back(v[i]);
        }

    }

    return ans;

}

vector<int> leaderInArray_optimal(vector<int> v){
    vector<int> ans;
    int n= v.size();
    // last one ia always leader
    ans.push_back(v[n-1]);
    int max = v[n-1];
    for(int i = n-2; i>=0;i--){
        if(v[i]>max){
            ans.push_back(v[i]);
            max = v[i];
        }
    }
    reverse(ans.begin() , ans.end());

    return ans;
}

int main (){
    vector<int> v = {10,22,12,3,0,6};
    cout<< "leaders " << endl;
    v = leaderInArray_brute(v);
    for(int it : v){
         cout<< it << " ";
    }

     return 0;
}