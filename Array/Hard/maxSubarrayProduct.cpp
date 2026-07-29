#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//  brute for is to check all suarray product

int maxmProduct(vector<int> v){
    int maxm = INT8_MIN;
    int pre = 1;
    int suf =1;
    int n =  v.size();
    for (int i = 0; i < n; i++)
    {   
        if(pre == 0){pre =1;};
        if(suf == 0){ suf=1;};
        pre*=v[i];
        suf*=v[n-i-1];
        maxm = max(maxm , max(pre ,suf));
    }
    return maxm;
    
}

int main (){
    vector<int> v ={2,3,-2,4};
    cout << "maxm product " << maxmProduct(v)<< endl;
    return 0;
}