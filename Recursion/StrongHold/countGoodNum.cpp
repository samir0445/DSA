#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
    long long power(int a,long long p){
    if(p==0){
        return 1;
    }
    if(p==1){
        return a;
    }

    if(p%2==0){ long long ans = (power(a,p/2))%MOD; return (ans*ans)%MOD;
    }else{
        long long ans = (power(a,p/2))%MOD;
        return (((a*ans)%MOD)*ans)%MOD;
    }
    }
    int countGoodNumbers(long long n) {
        if(n==1){
            return 5;
        }
        if(n % 2 == 0){
            long long h = n/2;
            long long re1 = power(5,h);
            long long re2 = power(4,h);
            long mul = (re1*re2)%MOD;
            return (int)mul;
        }
         long long h = n/2;
            long long re1 = power(5,h+1);
            long long re2 = power(4,h);
            long mul = (re1*re2)%MOD;
            return (int)mul;
        
    }

int main(){
    long long  n = 806166225460393;

    int res = countGoodNumbers(n);

    cout << " Total good number possible : " << res << endl;


    return 0;
}