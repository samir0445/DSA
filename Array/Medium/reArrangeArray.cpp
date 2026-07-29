#include<iostream>
#include<vector>
using namespace std;

void reArrange_Brute(vector <int>& v){
    int n = v.size();
    vector<int> pos;
    vector<int> neg;

    for(int i =0 ; i<n;i++){
        if(v[i]<0){
            neg.push_back(v[i]);
        }else{
            pos.push_back(v[i]);
        }
    }

    for(int i =0 ; i<n/2;i++){
        v[2*i] = pos[i];
        v[2*i +1] = neg[i];
    }

}

vector<int> reArrange_optimal(vector <int>& v){
    int n = v.size();
    vector<int> ans(n,0);
    int p=0;
    int ne=1;

    for(int i =0 ; i<n;i++){
        if(v[i]>0){
            ans[p] = v[i];
            p=p+2;

        }else{
            ans[ne] = v[i];
            ne=ne+2;

        }

    }
    return ans;
}

void rearrangeArray_notEqual(vector <int>& vec){
    vector <int> pos;
    vector <int> neg;
    int n = vec.size();
    for(int i =0; i<n;i++){
        if(vec[i]<0){
            neg.push_back(vec[i]);
        }else{
            pos.push_back(vec[i]);
        }
    }

    if(neg.size() < pos.size()){
        for (int i = 0; i < neg.size(); i++){
            vec[2*i] = pos[i];
            vec[2*i +1] = neg[i];
        }
        int newIdx = neg.size() *2;
        for(int i = neg.size(); i < pos.size(); i++){
            vec[newIdx++] = pos[i];

        }   
    }else{
        for (int i = 0; i < pos.size(); i++){
            vec[2*i] = pos[i];
            vec[2*i +1] = neg[i];
        }
        int newIdx = pos.size() *2;
        for(int i = pos.size(); i < neg.size(); i++){
            vec[newIdx++] = neg[i];

        }   

    }
}
int main(){
    vector <int> v ={3,-4,2,5,-7,-9};
    cout<< "After Rearrange "<< endl;
    
    for (int i =0 ; i<v.size();i++){
        cout << v[i] << " ";
    }
    cout<< endl;
    //  reArrange_Brute(v);
    // v = reArrange_optimal(v);

    for (int i =0 ; i<v.size();i++){
        cout << v[i] << " ";
    }

    // variation where NO of postive is not equal to no of  negative
    vector <int> vec ={3,-4,2,5,-7,-9,7,8,-3,2,-5,-6,-7};
    cout<< "After Rearrange "<< endl;
    
    for (int i =0 ; i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout<< endl;

    rearrangeArray_notEqual(vec);
    for (int i =0 ; i<vec.size();i++){
        cout << vec[i] << " ";
    }

    


    return 0;
}