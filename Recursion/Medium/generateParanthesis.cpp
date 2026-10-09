#include<bits/stdtr1c++.h>
using namespace std;

void helper(string curr,int open,int close,int n,vector<string>& ans){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
            helper(curr+'(',open+1,close,n,ans);
        }
        if(close<open){
             helper(curr+')',open,close+1,n,ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("",0,0,n,ans);

        return ans;
    }

    int main(){
        int n=3;
        vector<string> ans = generateParenthesis(n);

        for(string s : ans){
            cout << s << " ,";
        }

        return 0;
    }