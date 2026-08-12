#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
 
 
 string removeKdigits(string s, int k) {
        stack<int> st;
        int n = s.length();
        if(n == k){
            return "0";
        }

        for(int i=0;i<n;i++){
            int c = s[i]-'0';
            while(!st.empty() && k!=0 && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        if(k!=0){
            while(k!=0){
                st.pop();
                k--;
            }
        }
        string ans ="";
        while(!st.empty()){
            ans +=(st.top()+'0') ; 
            st.pop();
        }
        
        // removing leading zeros
        int i =ans.length()-1;
        while(i>=0){
            if(ans[i]=='0'){
                i--;
            }else{
                break;
            }
        }
        

        string num = ans.substr(0,i+1);
        if( num.empty()){return "0";}
        reverse(num.begin(),num.end());

        return num;

    }

int main(){

    string num = "102001";
    string ans= removeKdigits(num,1);
    cout <<"after remove k digits : " << ans << endl;

    return 0;
}