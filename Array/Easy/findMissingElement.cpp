#include<iostream>
#include<vector>
#include<math.h>

using namespace  std;
// prob: array contains array from range 1 to N but one single element will be missing we have to find that single missing element



// time( n^2)
int findElement_brute(int arr[],int n,int rng){

    for(int i=1;i<rng+1;i++){
       int flag = 0;
        for(int j = 0;j<n;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }

        }
        if(flag ==0){
            return i;
        }
       
    }
    return -1;

}

// hashing time( 2N) space N+1(array)
int findElement_better(int arr[],int n,int rng){
    // int maxm = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     maxm=max(arr[i],maxm);
    // }
    int hash[rng+1] = {0};
    for (int i = 0; i < n; i++)
    {
       hash[arr[i]]++;
    }
    // range is 1 to N so in hash index 0 will be always zero
    for (int i = 1; i <rng+1; i++)
    {
       if(hash[i]==0){
        return i;
       }
    }

    return -1;
    
    
}


//  time o(n)
int findElement_sum(int arr[],int n,int rng){
    int sum= (rng*(rng+1))/2;
    
    int ar_sum =0;
    for(int i =0;i<n;i++){
        ar_sum+=arr[i];
    }
    return sum - ar_sum;
}
// optimal o(N)


// striver video code
int findMissingElement(int a[],int n , int rng){
    int xor1 =0; int xor2=0;
    // the ideo is th
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1^a[i];
        xor2 = xor2^(i+1);
    }
    // here we hvae the add last element in xor2
    xor2= xor2^rng;
    return xor1^xor2;
    
}

int main(){
    int ar[] ={1,6,4,2,7,3};
    int n = sizeof(ar)/sizeof(ar[0]);  

    cout<<"single element : "<< findElement_brute(ar,n,7)<<endl;
    cout<<"single element : "<< findElement_better(ar,n,7)<<endl;
    cout<<"single element : "<< findElement_sum(ar,n,7)<<endl;
    cout<<"single element : "<< findMissingElement(ar,n,7)<<endl;

    return 0;
}