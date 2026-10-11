#include <bits/stdc++.h>
using namespace std;

void generate(int n,string s , char ls ,vector<string>& ans){

    if(n==0){
        ans.push_back(s);
        return;
    }

    // ls == 0
    if(ls=='0'){
        generate(n-1,s+'0','0',ans);
        generate(n-1,s+'1','1',ans);
    }

    if(ls=='1'){
         generate(n-1,s+'0','0',ans);
    }

}


vector<string> generateBinary(int n){
    vector<string> ans;
    generate(n-1,"0",'0',ans);
    generate(n-1,"1",'1',ans);
    return ans;
}


int main(){
    int n =3;

    vector<string> ans = generateBinary(n);

    for(auto s : ans){
        cout << s << "-";
    }

    return 0;
}