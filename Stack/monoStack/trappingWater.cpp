#include<bits/stdc++.h>
using namespace std;

    vector<int> prefix(vector<int>& a){
        vector<int> v;
        int n = a.size();
        int maxi = a[0];
        for(int i =0;i<n;i++){
            maxi = max(maxi,a[i]);
            v.push_back(maxi);
        }

        return v;
    }
    vector<int> suffix(vector<int>& a){
        int n = a.size();
        vector<int>s(n,0);
        int maxi = a[n-1];
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,a[i]);
            s[i] = maxi;
        }
        return s;
    }
    int trap(vector<int>& height) {
       vector<int> lefti = prefix(height);
       vector<int> righti = suffix(height);
       int n = height.size();

       int  total =0;
       for(int i =0;i<n;i++){

            if(height[i]<lefti[i] && height[i]<righti[i]){

                int val = min(lefti[i] ,righti[i]);
                total += (val - height[i]);
            }
       }

       return total;

        
    }
    int trapOptimal(vector<int>& height){
        int n = height.size();

       int  total =0;

       int leftmax = 0; int rightmax =0;
        int left =0;
        int right = n-1;
        while(left<=right){
            if(height[left]<height[right]){
                if(height[left]>=leftmax){
                    leftmax = height[left];
                }else{
                    total+= leftmax-height[left];

                }left++;
            }else{
                 if(height[right]>=rightmax){
                    rightmax= height[right];
                }else{
                    total+= rightmax-height[right];

                }
                right--;
            }
        }

       return total;
    }

int main(){

    // vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> h = {4,2,0,3,2,5};

    // int ans = trap(h);
    int ans = trapOptimal(h);
    cout<< " total trap water " << ans << endl;

    return 0;
}
