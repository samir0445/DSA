#include<iostream>
#include<vector>
using namespace std;

/*
problem is to find count that pair [i,j] where i>2*j
i shoulb in left side of j in original arr

*/
// int c=0;

void merge(vector<int>&v , int l,int m ,int h){
    vector<int> ans;
    // int cnt=0;
    int lo = l;
    int r = m+1;
    while(lo<=m && r<=h){
        if(v[lo]<=v[r]){
            ans.push_back(v[lo]);lo++;
        }else{
            ans.push_back(v[r]);
            // cnt+= (m-lo+1);
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
    
    
}

int countPair(vector<int>&v , int l,int m ,int h){
    int cnt =0;
    int r=m+1;
    for(int i=l;i<=m;i++){
        while(r<=h &&( v[i] >(2*v[r]))){r++;}
        cnt+=r-(m+1);
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
    c+=countPair(v,l,mid,h);
    merge(v,l,mid,h);
    return c;
}

int main(){
    vector<int> v ={2,4,3,5,1};
    int n = v.size();
    int ans = mergeSort(v,0,n-1);
    for(auto a:v){
        cout<<a<<' ';
    }
    cout<<ans<<" count ";

    return 0;
}