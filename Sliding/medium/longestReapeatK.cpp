#include<bits/stdc++.h>
using namespace std;
int longestRepeat(string s,int k){
    unordered_map<char,int> mp;
    int l=0;
    int r =0;
    int maxi =0;
    while (r<s.length())
    {
        mp[s[r]]++;

        while(mp.size()>k){
           mp[s[l]]--;
           if(mp[s[l]]==0){
            mp.erase(s[l]);
           }
           l++;
        }
        if(mp.size()<=k){
            int len = r-l+1;
            maxi = max(maxi,len);
        }
        r++;
    }
    return maxi;
    

}
int main(){
    string s ="AABBAVYTTUTTT";
    int k =2;
    int ans = longestRepeat(s,k);

    cout<< "LOngest : " << ans << endl;

    return 0;

    
}