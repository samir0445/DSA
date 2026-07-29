#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//  brute for is to check all suarray product

void print(int arr[] ,int n){
   
    for(int i =0;i<n;i++){
        cout << arr[i]<< ',';
    }cout<<" "<<endl;
}

void brute(int a1[],int a2[],int n,int m){
 int ans[n+m];
 int left =0;
 int right =0;
 int idx = 0;
 while(left<n && right < m){
    if(a1[left] <a2[right]){
        ans[idx++] = a1[left++];
  
    }else{
        ans[idx++] = a2[right++];
    }
 }
 while(left<n){
     ans[idx++] = a1[left++];
 }
 while(right<m){
     ans[idx++] = a2[right++];
 }

//  putting elements back in array
for(int i =0;i<n;i++){
    a1[i] = ans[i];
}
for(int i =0;i<m;i++){
    a2[i] = ans[n+i];
}
}

void optimal(int a1[],int a2[],int n,int m){
    int p1 = n-1;
    int p2 = 0;
    while(p1>=0 && p2<m){
        if(a1[p1] >a2[p2]){
            swap(a1[p1] ,a2[p2]);
            p1--;p2++;
        }else{
            break;
        }
    }
    sort(a1 , a1+n);
    sort(a2 , a2+m);
}
/*
 this problem has 2 optimal one is this and other

 other one is Gap method.. based on shell sort
 in that we have to take gap ceil of n+m/2..
 then set p1 and p2 on gap. then iterate and swap thhe element just likeabove

 then at the end og iteratin take ceil n/2  where n os the previous answer of seil..
 repeat process till gap >0 and break loop when gap == 1 because it go to infite loop where n/1 alway gieves 1.
*/


int main (){
   int arr1[] = {1,3,6,8};
   int arr2[] = {0,2,5,7,9};
   int n =(sizeof(arr1)/sizeof(arr1[0]));
   int m =(sizeof(arr2)/sizeof(arr2[0]));
   print(arr1 , 4);
   print(arr2, 5);
//    brute(arr1,arr2,4,5);

  optimal(arr1,arr2,4,5);

   cout<< "after merge " <<endl;
   print(arr1,4);
   print(arr2,5);





    cout << "maxm product " << endl;
    return 0;
}