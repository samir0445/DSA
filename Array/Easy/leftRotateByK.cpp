#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// k*n
void leftRotate_brute(int a[],int n,int k){
     k = k%n;
for (int i = 0; i < k; i++)
{ int a1 = a[0];
    for (int j = 0; j < n-1; j++)
    {
        a[j]=a[j+1];
    }
    a[n-1]=a1;
    
}
}

void leftRotate_better(int a[],int n,int k){
    k=k%n;
    int temp[k];
    for(int j=0;j<k;j++){
        temp[j]=a[j];
    }
    for (int i = k; i < n; i++)
    {
        a[i-k]=a[i];
    }
    for (int j = n-k; j < n; j++)
    {
        a[j]=temp[j-(n-k)];
    }   
}
void leftRotateByK(int a[],int n ,int k){
//  for leetcode k = n-k logic wise


    reverse(a,a+k);
    reverse(a+k,a+n);
    reverse(a,a+n);
}
int main(){
    int a[]={5,6,7,8,91,90}; //8 7 6 5 90 91  91 90 5 6 7 8

    int n = sizeof(a)/sizeof(a[0]);
    int k=4;

    leftRotateByK(a,n,k);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" , ";
    }
    
    
    return 0;
}
