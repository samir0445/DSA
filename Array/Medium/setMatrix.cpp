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

void change_row(vector<vector<int>>& mtx , int i,int c){
    for(int k=0;k<c;k++){
        if(mtx[i][k] != 0){

            mtx[i][k] = -1;
        }
    }
}
void change_col(vector<vector<int>>& mtx , int j,int r){
    for(int k=0;k<r;k++){
        if(mtx[k][j] != 0){

            mtx[k][j] = -1;
        }
    }
}
void setMatrix_brute(vector<vector<int>>& mtx , int n,int m){
    for(int i = 0 ; i<n;i++){
        for(int  j=0; j<m ; j++){
            if(mtx[i][j]==0){
                change_row( mtx ,i , m);
                change_col( mtx , j,n);
            }
            
        }
       
    }

    for(int i = 0 ; i<n;i++){
        for(int  j=0; j<m ; j++){
            if(mtx[i][j]== -1){
                mtx[i][j]= 0;
            }
            
        }
       
    }


}

void setMatrix_better(vector<vector<int>>& mtx , int n,int m){
    vector<int> row (n,0);
    vector<int> col(m,0);

    for(int i = 0 ; i<n;i++){
        for(int  j=0; j<m ; j++){
            if(mtx[i][j]==0){
                row[i] =1;
                col[j] =1;
            }    
        }
    }

    for(int i = 0 ; i<n;i++){
        for(int  j=0; j<m ; j++){
            if(row[i] == 1 || col[j] ==1){
                mtx[i][j] =0;
            }    
        }
    }

}


void setMatrix(vector<vector<int>>& mtx , int n,int m){
    int col0 =1;

    for(int i = 0 ; i<n;i++){
        for(int  j=0; j<m ; j++){
            if(mtx[i][j]==0){
                if(j !=0 ) {
                    mtx[0][j] =0;
                    
                }else{
                    col0 =0;
                }

                mtx[i][0] =0;
            }    
        }
    }

    for(int i = 1 ; i<n;i++){
        for(int  j=1; j<m ; j++){
            if(mtx[i][j] != 0){
                if(  mtx[0][j] ==0 || mtx[i][0] ==0){
                    mtx[i][j] = 0;
                }

            }
               
        }

        if(mtx[0][0] == 0){
            for(int i = 0 ;i<m;i++){
                mtx[0][i]=0;
            }
        }

        if(col0 ==0){
            for(int i = 0 ;i<n;i++){
                mtx[i][0]=0;
            }
        }
    }
}
int main(){
    vector<vector<int>> mtx = {{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};

    int r = mtx.size();
    int c = mtx[0].size();
    print(mtx,r,c);
    cout << "after" << endl;

    // setMatrix_brute(mtx,r,c);
    // setMatrix_better(mtx,r,c);
    setMatrix(mtx,r,c);

    print(mtx,r,c);



    


    return 0;
}