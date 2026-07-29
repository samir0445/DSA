#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> sum3_brute(vector <int> v){
    int n= v.size();
   
    set<vector<int>> s;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){ 
                    if(v[i]+v[j]+v[k]+v[l]==0){
                        vector<int> temp = {v[i],v[j],v[k],v[l]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
    }
    }
    }
      vector<vector<int>> ans(s.begin(),s.end());
    return ans;

}

vector<vector<int>> sum3_better(vector <int> v){
    int n= v.size();
   
    set<vector<int>> s;

    for(int i=0;i<n;i++){     
        for(int j=i+1;j<n;j++){
            set<int> hash;
            for(int k=j+1;k<n;k++){
                // for specific target
                // fourth = target - (v[i]+v[j]+v[k])
                int fourth = -(v[i]+v[j]+v[k]);
                if(hash.find(fourth) != hash.end()){
                    vector<int> temp ={v[i],v[j],v[k],fourth};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                hash.insert(v[k]);
            }

    }
    }
      vector<vector<int>> ans(s.begin(),s.end());
    return ans;

}

vector<vector<int>> sum3(vector <int> &v){
    int n= v.size();
    sort(v.begin(),v.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(i>0 && v[i]==v[i-1])continue;
        for(int j = i+1;j<n;j++){
            if(j!=i+1 && v[j]==v[j-1])continue;

            int k=j+1;
            int l = n-1;
            while(k<l){
                int sum = v[i]+v[j]+v[k]+v[l];
                if(sum<0){
                    k++;
                }else if(sum>0){
                    l--;
                }else{
                    vector<int> temp = {v[i],v[j],v[k],v[l]};
                    ans.push_back(temp);
                    k++;l--;
                    while(k<l && v[k]==v[k-1]){k++;}
                    while(k<l && v[l]==v[l+1]){l--;}
    
                }
            }
        }
        

        
    }
    return ans;

}



int main (){
    vector<int> v ={-1,1,-1,0,2,-2};

    // vector<vector<int>> ans = sum3_brute(v);
    // vector<vector<int>> ans = sum3_better(v);
     vector<vector<int>> ans = sum3(v);

    for(auto a : ans){
       for(auto k : a){
        cout<< k << " ";
       }
        cout<< "," <<endl;

    }
    return 0;
}