#include<bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector<int>& bar) {
        stack<int>st;
        int n = bar.size();
        int maxi =0;
        for(int i =0;i<n;i++){
            while(!st.empty()&& bar[st.top()]>bar[i]){
                int el = st.top(); st.pop();
                int pse = st.empty() ? -1 : st.top();
                int area = bar[el] * (i - pse -1);
                maxi = max(maxi,area);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;

            int el = st.top(); st.pop();
            
            int pse = st.empty() ? -1 : st.top();
            

            int area = bar[el] * (nse - pse -1);
                maxi = max(maxi,area);
        }

        return maxi;
        
    }

int main(){

    vector<int> bar = {2,1,5,6,2,3};

    cout<< " largest reactangle area : " << largestRectangleArea(bar)<<endl;

    return 0;
}