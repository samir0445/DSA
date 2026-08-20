#include<bits/stdc++.h>
using namespace std;
void checkInsert(stack<int>& st,int top){
    if(st.empty() || st.top()<=top){
        st.push(top); return;
    }
    int temp = st.top();
    st.pop();
    checkInsert(st,top);

     st.push(temp);

}
void sortStack( stack<int>& st){
    if(st.empty()) return;

    int top = st.top();
    st.pop();
    sortStack(st);
    checkInsert(st,top);

}
    




int main(){
    stack<int> st;
    st.push(4);
    st.push(2);
    st.push(6);
    st.push(1);
    st.push(0);

    

    // [4 2 6 1 0]

    sortStack(st);

    while(!st.empty()){
        cout<< st.top() << " , ";
        st.pop();
    }

    return 0;
}