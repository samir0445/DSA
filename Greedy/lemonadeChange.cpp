#include<bits/stdc++.h>
using namespace std;



bool lemonadeChange(vector<int>& bills) {
        unordered_map <int,int> coins;
        coins[5] =0;
        coins[10] = 0;
        coins[20] =0;
        int n = bills.size();

        for(int i=0;i<n;i++){
            if(bills[i] == 5){
                coins[bills[i]]++;
            }else if(bills[i] == 10){
                if(coins[5]>0){
                    coins[5]--;
                    coins[10]++;
                }else {
                    return false;
                }

            }else {
                if(coins[10]>=1 && coins[5]>=1){
                    coins[10]--;
                    coins[5]--;
                    coins[20]++;
                }else if(coins[5]>=3){
                    coins[5] -= 3;
                    coins[20]++;
                }else {
                    return false;
                }
            }

        }

        return true;

        
    }

    int main(){

        vector<int> bills = {5,5,5,10,20};
        cout << " possible : " << lemonadeChange(bills)<< endl;

        

        return 0;
    }