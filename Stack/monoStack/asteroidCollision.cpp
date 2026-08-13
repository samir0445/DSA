#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

    int abs(int x){
        if(x<0){
            return x*-1;
        }
        return x;
    }
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        int n = ast.size();
        for(int i =0;i<n;i++){
            if(ast[i]> 0){
                st.push(ast[i]);
            }else{
                while(!st.empty() && st.top()>0 && st.top()<abs(ast[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(ast[i])){
                    st.pop();
                }else if( st.empty() || st.top() <0){
                    st.push(ast[i]);
                }
            }
        }

        vector<int> ans;
        if(st.empty()) return ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }

int main(){
    vector<int> asts = {3,5,-6,2,-1,4};
    vector<int> ans = asteroidCollision(asts);
    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}
