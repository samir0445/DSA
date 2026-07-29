#include<iostream>
#include<vector>
using namespace std;

/*
problem is to find count that pair [i,j] where i>j
i shoulb in left side of j in original arr

*/
// int c=0;

int merge(vector<int>&v , int l,int m ,int h){
    vector<int> ans;
    int cnt=0;
    int lo = l;
    int r = m+1;
    while(lo<=m && r<=h){
        if(v[lo]<=v[r]){
            ans.push_back(v[lo]);lo++;
        }else{
            ans.push_back(v[r]);
            cnt+= (m-lo+1);
            r++;
        }
    }

    while (lo<= m){
        ans.push_back(v[lo]);lo++;
    }
    while (r<=h)
    {
       ans.push_back(v[r]);r++;
    }
    for(int i=l ; i<=h;i++){
        v[i] = ans[i-l];
    }
    return cnt;
    
}
int mergeSort(vector<int>&v , int l,int h){
   int c =0;
    if(l>=h){
        return c;
    }
    
    int mid = (l+h)/2;
    c+=mergeSort(v,l,mid);
    c+=mergeSort(v,mid+1,h);
    c+=merge(v,l,mid,h);
    return c;
}

int main(){
    vector<int> v ={3,2,5,6,9,8,1,2,4};
    int n = v.size();
    // mergeSort(v,0,n-1);
    for(auto a:v){
        cout<<a<<' ';
    }
    cout<< mergeSort(v,0,n-1)<<" count ";

    return 0;
}