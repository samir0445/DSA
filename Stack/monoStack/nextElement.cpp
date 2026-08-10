#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

// this logic is not correct

vector<int> nextElement_naive( vector<int>v1 ,vector<int> v2){
    int n1 = v1.size();
    int n2 = v2.size();

    stack<int> st;
    unordered_map<int,int> mpp;
    vector<int> ans ;
    for(int i=0;i<n2;i++){
        st.push(v2[i]);
    }
    mpp[st.top()] =-1;
    int pre =st.top();
    st.pop();

    while(!st.empty()){
        int top = st.top();
        mpp[top] = top<=pre?pre:mpp[pre];
        pre = top;
        st.pop();
    }
    for(int i=0;i<n1;i++){
        ans.push_back(mpp[v1[i]]);
    }
    return ans;
    
    
}
vector<int> nextElement( vector<int>v1 ,vector<int> v2){

        stack<int> st;
                unordered_map<int,int>mpp;
                vector<int>ans;
        
                
                int n2 = v2.size();
                int n1 = v1.size();
        
                for(int i = n2-1;i>=0;i--){
                    if(st.empty()){
                        mpp[v2[i]]=-1;
                        
                    }else{
                        while(!st.empty() && st.top()<v2[i]){
                            st.pop();
                        }
                        if(st.empty()){
                            mpp[v2[i]]=-1;
                        
                            
                        }else{
                            mpp[v2[i]]=st.top();
                        
                        }
                    }
                    st.push(v2[i]);
                }

                for(int i=0;i<n1;i++){
            ans.push_back(mpp[v1[i]]);
        }

        return ans;
}

int main(){
    vector<int> v1 ={4,1};
    vector<int> v2 ={2,3,1,4};

    vector<int> ans = nextElement(v1,v2);

    for(auto n : ans){
        cout<< n << " ,";
    }

    return 0;
}