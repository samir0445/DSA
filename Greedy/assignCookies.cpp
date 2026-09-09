#include<bits/stdc++.h>
using namespace std;



int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j =0;
        int cnt=0;
       while(i<g.size() && j<s.size()){
            if(s[j] >=g[i]){
                cnt++;i++;j++;
            }else{
                j++;
            }
       }

       return cnt;
    }

int main(){

    vector<int> g ={1,2,3};

    vector<int> s ={1,3,3};

    int ans = findContentChildren(g,s);

    cout << " maximum chid can have according to greed : " <<  ans << endl;

    return 0;
}