#include<iostream>
using namespace std;
bool isSorted(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int a[]={5,6,7,8,91,90};
    int n = sizeof(a)/sizeof(a[0]);
    bool isSort = isSorted(a,n);
    if(isSort){
        cout<<"sorteed";
    }else{
        cout<<"not sorted";
    }
    return 0;
}
