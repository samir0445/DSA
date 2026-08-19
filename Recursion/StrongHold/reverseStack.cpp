#include<bits/stdc++.h>
using namespace std;

void reverse( stack<int>& st){
    if(st.empty()) return;

    int top = st.top();
    st.pop();
    reverse(st);
    st.push(top);

}





int main(){
    stack<int> st;
    st.push(4);
    st.push(2);
    st.push(6);
    st.push(1);
    st.push(0);

    stack<int> ans;

    // [4 2 6 1 0]

    reverse(st);

    while(!st.empty()){
        cout<< st.top() << " , ";
        st.pop();
    }

    return 0;
}