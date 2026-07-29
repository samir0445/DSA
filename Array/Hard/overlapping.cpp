#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
logic:
create ans vector and iterate given interval vector
sort the vector by first value
case1:
if ans is empty or ans.last elemets upper limt < currretn iterating alement lower limt
    means  the current iterval paiit no the overlappig to the last pair which we had enter in answe
    then add that elemet as new interval

cas 2:
 ans last pairs  upper limit is > cuuren t elments lower limit
 means the current pair is the part of that last tuple_element_t
  sowe have to extend upper limt of ans elemt wiht max of current and ans upper

  */

vector<vector<int>> overlapping(vector<vector<int>> v){
    vector<vector<int>> ans;
    int n = v.size();
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){
        if(ans.empty() || v[i][0]>ans.back()[1]){
            ans.push_back(v[i]);
        }else{
            ans.back()[1] = max(v[i][1],ans.back()[1]);
        }
    }
    return ans;
}

vector<vector<int>> overlapping_brute(vector<vector<int>> v){
    int n = v.size();
    sort(v.begin(),v.end());
    vector<vector<int>> ans;

    for(int i =0;i<n;i++){
        int start = v[i][0];
        int end = v[i][1];
        if(!ans.empty() && end<= ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(end>=v[j][0]){
                end = max(end,v[j][1]);

            }else{
                i=j-1;
                break;
            }
        }
        ans.push_back({start , end});

    }
    return ans;
}


int main(){
    vector<vector<int>> v= {{1,3},{2,6},{8,10},{15,18}};
    // vector<vector<int>> ans = overlapping(v);
    vector<vector<int>> ans = overlapping_brute(v);

     for(auto a : ans){
       for(auto k : a){
        cout<< k << " ";
       }
        cout<< "," <<endl;

    }
    return 0;
}