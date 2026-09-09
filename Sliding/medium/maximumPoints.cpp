#include<iostream>
#include<vector>
using namespace std;


    int maxScore(vector<int>& cards, int k) {
        int maxi =0;
        if(k == cards.size()){
            int sum =0;
            for(int i=0;i<cards.size();i++){
                sum+=cards[i];
            }
            return sum;
        }else if(k==1){
            return max(cards[0],cards[cards.size()-1]);
        }
        int ls =0;
        int rs=0;
        int sum =0;
        for(int i=0;i<k;i++){
                sum+=cards[i];
         }
         ls = sum;
         maxi = max(maxi,ls);
         int right = cards.size()-1;

         for(int i=k-1;i>=0;i--){
            sum = sum - cards[i];
            sum = sum + cards[right];
            right--;
            maxi = max(maxi,sum);
         }
            return maxi;
        

    }

int main(){
    vector<int> cards = {1,2,3,4,5,6,1};
    int k =3;
    cout<< " maximum points : " << maxScore(cards,k)<<endl;
    

    return 0;
}