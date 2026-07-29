// prob: to return the count of all total unique element after removeing duplicates

#include<iostream>
#include<vector>
#include<set>
using namespace std;

// brute time(nlogn(insertin set) + n) space(n)
int removeDuplicate(int a[],int n){
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
int index=0;
    for(auto it:s){
        a[index++]=it;

    }
    return index;
    // donot retunr index+1 because  in loop we are using index++ 

}

// two pointer
int removeDuplicates(int arr[],int n){
int i=0;
for (int j = 1; j < n; j++)
{
    if(arr[i]!=arr[j]){
        arr[i+1]=arr[j];
        i++;
    }
    
}
return i+1;
// at the end i will be the index of last unique ans so retunr count it will be i+1

}

int main(){
    int arr[]={1,1,2,3,4,4,5,5,8,8,9,10,11,12,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans =removeDuplicates(arr,n);
    cout<<"count after remove duplicates : "<<ans<<endl;

    return 0;

}