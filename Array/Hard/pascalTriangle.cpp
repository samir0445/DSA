#include<iostream>
#include<vector>
using namespace std;

vector<int> row(int n){
    vector<int> r;
    int up=1;
    int down =1;
    for(int i=0;i<n;i++){
        if(i==0 || i== n-1){
            r.push_back(1);
        }else{
            up*=n-i;
            down *=i;
            r.push_back(up/down);

        }
    }
    return r;

}

int main(){
    int n;
    vector<vector<int>> v;
    cout<<"enter n "<<endl;
    cin>>n;
    for(int i =0;i<n;i++){
        vector<int> ans = row(i+1); 
        v.push_back(ans);
    }
    for(auto r : v){
        for(auto a : r){
         cout<< a<<' ';
    }
         cout<<endl;
    };
    return 0;
}