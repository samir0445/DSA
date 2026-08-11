#include<iostream>
#include<stack>
#include<vector>

using namespace std;




vector<int> preElement(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            /*
            arr[st.top()] >=arr[i] >= is used to had the duplicate......
            */
            while (!st.empty() && arr[st.top()] >=arr[i]) {
                st.pop();
            }
            int val = st.empty() ? -1 : st.top();
            ans[i] = val;
            st.push(i);
        }

        return ans;
    }
    vector<int> postElement(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            int val = st.empty() ? n : st.top();
            ans[i] = val;
            st.push(i);
        }

        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pre = preElement(arr);
        vector<int> post = postElement(arr);
        int mod = 1e9 + 7;
        long long total = 0LL;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int preidx = i - pre[i];
            int postIdx = post[i] - i;
            long long fre = (preidx * postIdx * 1LL );
            int val = (fre*arr[i]*1LL)%mod;

            total = (total + val)%mod ;
        }

        return (int)total;
    }

int main(){

    vector<int> arr={2,2};

    int sum = sumSubarrayMins(arr);
    cout<<" sum of all possible subarrays min : " << sum << endl;

    return 0;
}