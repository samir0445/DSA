#include<iostream>
#include<vector>
using namespace std;

// brute time(n+k+(n-k)) space(K)
void moveToEnd(int a[], int n){
    vector<int>v;
    // first take out all non zero
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            v.push_back(a[i]);
        }
    }
    for(int i=0;i<v.size();i++){
        a[i]=v[i];
    }
    for(int i = v.size();i<n;i++){
        a[i]=0;
    }
}

void moveZeroToEnd(int a[], int n){
    int i;
    // first find first index of where 0 is
    for(int j=0;j<n;j++){
        if(a[j]==0){
            i=j;
            break;
        }
    }

    for(int j=i+1;j<n;j++){
        if(a[j]!=0){
            swap(a[i],a[j]);
            i++;
        }
    }
}



int main(){
    int a[]={5,0,7,0,0,1,3,0,8,0,0,9,6};
    int n = sizeof(a)/sizeof(a[0]);
    // moveToEnd(a,n);
    moveZeroToEnd(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<",";
    }
    
    return 0;
}
