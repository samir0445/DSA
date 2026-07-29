#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> mt ={{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    int n = mt.size();
    int m = mt.size();
    vector<int> ans;

    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1 ;

    while(top<=bottom && left<=right){

        for(int i = left;i<=right;i++){
            ans.push_back(mt[top][i]);
        }
        top++;
        for(int i = top;i<=bottom;i++){
            ans.push_back(mt[i][right]);
        }
        right--;
        if(top<=bottom){

            for(int i = right;i>=left;i--){
                ans.push_back(mt[bottom][i]);
            }
            bottom--;
        }

        if(left<=right){

            for(int i = bottom;i>=top;i--){
                ans.push_back(mt[i][left]);
            }
            left++;
        }
    }

    for(int n:ans){
        cout << n << " ";
    }
    return 0;
}