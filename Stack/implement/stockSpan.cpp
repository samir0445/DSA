#include<bits/stdc++.h>
using namespace std;


class StockSpanner {
public:
    stack<pair<int,int>> st;
    
    StockSpanner() {
    }
    
    int next(int price) {
     int span =1;
      while(!st.empty() && st.top().first <= price){
        span +=st.top().second;
        st.pop();
      }
        st.push({price,span});
        return span;

    }
};

int main(){
    StockSpanner st =  StockSpanner();
    st.next(100);
    st.next(80);
    st.next(50);
    int ans = st.next(60);

    cout << " stock span : " << ans << endl;



    return 0;
}