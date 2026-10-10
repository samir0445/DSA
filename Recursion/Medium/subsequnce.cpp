#include<bits/stdc++.h>
using namespace std;

void solve(string s,string set,int idx, vector<string>& ans){
    if(idx>= s.length()){
        ans.push_back(set);
        return;
    }

    // ignore
    solve(s,set,idx+1,ans);

    // add
    set += s[idx];
    solve(s,set,idx+1,ans);
}

vector<string> subsets(string s){
    vector<string> ans;
   
    string seq ="";
    solve(s,seq,0,ans);
    return ans;
}
int main(){
    string s = "abc";
    vector<string> ans = subsets(s);

    for(auto it : ans){
      
       cout << it << " | ";
    }

    return 0;
}