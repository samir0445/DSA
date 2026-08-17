
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> mat;
        int r = matrix.size();
        int c = matrix[0].size();
        // mat.push_back({matrix[0]});
        // creating prefic martix
        vector<int> rol(c,0);           
            for(int j =0;j<c;j++){
               int val = matrix[0][j]-'0';
               rol[j] = val;
            }
        mat.push_back(rol);
        for(int i=1;i<r;i++){
            vector<int> ro(c,0);           
            for(int j =0;j<c;j++){
               int val = (matrix[i][j]-'0') ==0 ? 0 : (mat[i-1][j]+1); 
               ro[j] = val;
            }
            mat.push_back(ro);
        }

        int maxi =0;
        for(int i =0;i<r;i++){
            int res = largestRectangleArea(mat[i]);
            maxi = max(maxi,res);
        }

        return maxi;
        
    }

    int main(){
        vector<vector<char>> matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
};
        cout<< " maximum reactange of 1s : " << maximalRectangle(matrix)<<endl;



        return 0;
    }