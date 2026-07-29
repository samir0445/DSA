
/*
1 2 3 4 2  [2,5] 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> missingRepeat(vector<int>&v){
    int n = v.size();
    int st = n*(n+1)/2;
    int st2 = (n*(n+1)*(2*n+1))/6;

    int s =0;
    int sn = 0;
    for(int i = 0;i<n;i++){
        s += v[i];
        sn += v[i]*v[i]; 
    }
    int q1 = s-st; //X-y
    int q2 = sn-st2; // x2-y2
    int q3 = q2/q1; // x+y

    int x = (q1+q3)/2;
    int y =x-q1;


    return {x,y};
}

int main(){

    vector<int> v = {1, 2, 3, 6, 7, 5, 4,7};
    vector<int> ans = missingRepeat(v);
    cout <<"Repeat :" << ans[0] <<  "and Missing :" << ans[1]<<endl;

    return 0;
}