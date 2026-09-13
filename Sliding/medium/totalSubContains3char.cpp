#include<bits/stdc++.h>
using namespace std;

    int numberOfSubstrings(string s) {
        vector<int> mp(3,-1);
        int cnt=0;

        for(int i=0;i<s.length();i++){
            mp[s[i]-'a'] =i;
            if(mp[0]!=-1 && mp[1]!=-1 && mp[2]!=-1){
                int mini = min(mp[0],mp[1]);
                mini = min(mini,mp[2]);
                cnt = cnt + (1+mini);
            }
        }
        return cnt;
    }

    int main(){
        string s = "aaabc";
        int ans  = numberOfSubstrings(s);
        cout<< "total Substrings : " << ans << endl;
        return 0;
    }
