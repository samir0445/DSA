#include<iostream>
using namespace std;

void leftRotateByOne(int a[],int n){
    int a1 = a[0];
    for (int i = 0; i < n-1; i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=a1;

}
void rightRotateByOne(int a[],int n){
    int a1 = a[n-1];
    for (int i = n-1; i >=0; i--)
    {
        a[i]=a[i-1];
    }
    a[0]=a1;

}

int main(){
    int a[]={5,6,7,8,91,90};
    int n = sizeof(a)/sizeof(a[0]);
    // leftRotateByOne(a,n);
    rightRotateByOne(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<< " ,";
    }
    

    
    return 0;
}
