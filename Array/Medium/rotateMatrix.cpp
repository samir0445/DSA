#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<vector<int>> mtx , int n,int m){
    for(int i = 0 ; i<n;i++){
        for(int  j=0; j<m ; j++){
            cout << mtx[i][j] << " ";
        }
        cout<< endl;
    }

}

vector<vector<int>> rotateMatrix_brute(vector<vector<int>>& mat,int n,int m){
    vector<vector<int>> arr(m, vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j = 0; j<m;j++){
            arr[j][n-1-i] = mat[i][j];
        }
    }

    return arr;

}

void rotateMatrix(vector<vector<int>>& mat,int n,int m){

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<m;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
}

int main(){

    vector<vector<int>> mat ={{1,2,3},{4,5,6},{7,8,9}};
    int n= mat.size();
    int m = mat[0].size();

    print(mat,n,m);
    // vector<vector<int>> ans= rotateMatrix_brute(mat,n,m);
    rotateMatrix(mat,n,m);
    cout<<endl;
    print(mat,n,m);




    return 0;
}