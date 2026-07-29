#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

/*
just flow this step
step 1 :
    find the break point where i th element becamr less then i+1
    in next permutation where are trying ot find next greater number than what wwe have to achieve that  we travel from back and come element. if set atrevese asc than we cannnot find high  then  we have to find the point where this order end 
step 2 :
    exchange the break point with the cloest greater value
    we fidnt his by traverse from back beaces thae are sorted so first element whcihc is greater than brpoint is closest greater swap both elemet
step 3 :
    after that we have to set remaing part sorted we can apply sorting algo but is we just reverse that remaing part that also give us sorted becase wecswap eelmt

*/

void next_permutation(vector<int> &v){
   int n = v.size(); 
    int point = -1;
    for(int i = n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            point = i;
            break;
        }
    }

        if(point == -1){
            reverse(v.begin() , v.end());
            return;
        }

        for(int i = n-1;i>point;i--){
            if(v[point]<v[i]){
                swap(v[point],v[i]);
                break;
            }
        }

        reverse(v.begin() + point + 1 , v.end());
    
}

int main(){

    vector <int> v = {2,1,5,4,0,0};
    cout<< " next permutation " << endl;
    next_permutation(v);

    for(int i : v){
        cout << i << ' ';
    }


    return 0;
}
