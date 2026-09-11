#include<bits/stdc++.h>
using namespace std;

int fruitpick(vector<int>v){
    unordered_map <int,int> hs;

    int l=0;
    int maxi =0;
    for(int r =0;r<v.size();r++){
        hs[v[r]]++;
        while(hs.size()>2){
            hs[v[l]]--;
            if(hs[v[l]] ==0){
                hs.erase(v[r]);
            }
            l++;
        }
        maxi = max(maxi , r-l+1);
    }

    return maxi;

}
int main(){
    vector<int> v = {3,3,3,2,2,2,3,1};
    cout << "Maxim fruits : " << fruitpick(v)<<endl;

    return 0;
}