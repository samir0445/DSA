#include <bits/stdc++.h>
using namespace std;

const int INT_MIN_VAL = -2147483648;
const int INT_MAX_VAL = 2147483647;

// Recursive helper
int helper(const string &s, int i, long long num) {
    if(i>=s.length() || (!isdigit(s[i]))){
        return (int)num;
    }

    num= num*10 +(s[i]-'0');
    if(num>=INT_MAX_VAL){
        return INT_MAX_VAL;
    }
    
    return helper(s,i+1,num);

}

int myAtoi(string s, int i = 0) {
    while(s.length()>i && s[i]==' '){
        i++;
    }
    if(s.length()==0){
        return 0;
    }

    int sign =1;
    if(i<s.length() && (s[i] =='+'|| s[i]=='-')){
       sign= s[i]=='-'? -1:1;
       i++;

    }
    
    return sign * helper(s,i,0);
   
}

int main() {
    string s = "  4193 with words";
    cout << myAtoi(s) << endl; 
    return 0;
}