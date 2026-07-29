// int prob in unionn of 2 array  will be array of all unique union elemnts
// both array wiill be sorted

#include<iostream>
#include<vector>
#include<set>
#include<array>

using namespace std;

// brute time(2NlogN + n) space(set and vectore ans)
vector<int> unionArr(int a1[],int a2[], int n1,int n2){
    set<int> s;
    for(int i=0;i<n1;i++){
        s.insert(a1[i]);
    }
    for(int i=0;i<n2;i++){
        s.insert(a2[i]);
    }
    vector <int> ans;
    
    for(auto it:s){
       ans.push_back(it);
    }
    return ans;

}

// two pointer both arr is sorted
vector<int> unionOfArr(int a1[],int a2[], int n1,int n2){
 vector<int> ans;
 int i=0,j=0;
 while(i<n1 && j<n2){
    if(a1[i]<=a2[j]){
        if( ans.size()==0 || ans.back() != a1[i] ){
            ans.push_back(a1[i]);
            
        }
        i++;
    }
    else{
        if( ans.size()==0 || ans.back() != a2[j]   ){
            ans.push_back(a2[j]);
            
        }
        // j++ should run in both case if item get pushback or not
        j++;
    }
 }

 while(j<n2){
    if( ans.size()==0 ||ans.back() != a2[j]  ){
            ans.push_back(a2[j]);
            
        }
        j++;
 }
 while(i<n1){
    if(  ans.size()==0 || ans.back() != a1[i]  ){
            ans.push_back(a1[i]);
            
        }
        i++;
 }

 return ans;
}

vector<int> intersaction(int a1[],int a2[], int n1,int n2){
    vector<int> ans;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            i++;
        }else if(a1[i]>a2[j]){
            j++;
        }else{
            ans.push_back(a1[i]);
            i++;
            j++;
        }
    }

    return ans;
}
int main(){
    int a1[]={1,1,2,2,3,4,5,6};
    int a2[]={1,1,1,3,5,7,8,9};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int n2 = sizeof(a2)/sizeof(a2[0]);
    //  vector <int> a =unionArr(a1,a2,n1,n2);
    // vector<int> v =unionOfArr(a1,a2,n1,n2);
    vector<int> v =intersaction(a1,a2,n1,n2);

     for (int i = 0; i < v.size(); i++)
     {
        cout<<v[i]<<" ,";
     }
     
   
    return 0;
}
