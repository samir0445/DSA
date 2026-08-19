#include<bits/stdc++.h>
using namespace std;


long long power(long long a,int p){
    if(p==0){
        return 1;
    }
    if(p==1){
        return a;
    }

    if(p%2==0){ long long ans = power(a,p/2); return ans*ans;
    }else{
        long long ans = power(a,p/2);
        return a*ans*ans;
    }
}

int main(){
    int a = 5LL;
    int  p= 25;
    cout<< p<<" of  " << a << " / " << a << " ^ " << p<<": " << power(a,p) << endl;
    return  0;
}
