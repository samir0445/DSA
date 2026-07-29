#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// optimse
int secondLargest(vector <int> &v,int n){
    int large = v[0];
    int slarge = INT8_MIN;
    for(int i=0;i<=n-1;i++){
        if(v[i]>large){
            slarge=large;
            large=v[i];
        }
    }
    return slarge;
}
int secondSmallest(vector <int> &v,int n){
    int small = v[0];
    int sndSmall = INT8_MAX;
    for(int i=0;i<=n-1;i++){
        if(v[i]<small){
            sndSmall=small;
            small=v[i];
        }
    }
    return sndSmall;
}


// brute better
int secondLarge(vector <int> &v,int n ){
    int large=v[0],slarge=INT8_MIN;
    for(int i =1;i<=n-1;i++){
        if(v[i]>large){
            large=v[i];
        }
    }
    for(int i =1;i<=n-1;i++){
        if(v[i]<large && v[i]>slarge){
            slarge=v[i];
        }
    }
    return slarge;
}

int main(){
    vector <int> v = {83,4,5,6,2,4,6,7,9,6,56,78,90};

    // cout<<"second large "<< secondLarge(v,v.size())<<endl;

    cout<<"second large "<< secondLargest(v,v.size())<<endl;
    cout<<"second small "<< secondSmallest(v,v.size())<<endl;


    return 0;
}