#include<iostream>
using namespace std;

int maxConsecutiveOnes(int a[],int n){
    int maxlen=0;
    int count=0;
    
    
    for (int i = 0; i < n; i++)
    {  if(a[i]==1){
        count++;
       
        
        }else{
             maxlen=max(maxlen,count);
            count =0;
         }
        
    }
    return max(maxlen,count);
    
}
int main(){
    // int arr[]={0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1,1,1,1,1,1,1,0,0,0,1};
    int arr[]= {1,1,0,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"maximum consecutive 1's :  "<<maxConsecutiveOnes(arr,n)<<endl;
    return 0;
}