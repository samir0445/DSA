#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
bool linearSearch(vector<int> v, int target)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] == target)
        {
            return true;
        }
    }
    return false;
}

int longestConSubSeq_brute(vector<int> v)
{ int n = v.size();
    int longest =0;
    for(int i=0;i<n;i++){
        int curr =1;
        int next = v[i]+1;
        while(linearSearch(v,next) == true){
            curr++;
            next++;
        }
        longest = max(longest,curr);
    }

    return longest;
}

int longestConSubSeq_better(vector<int> v){
    sort(v.begin() , v.end());
    int n = v.size();
    int longest =0;
    int lastSmall = INT8_MIN;
    int curr=0;

    for(int i=0 ;i<n;i++){
        if(v[i]-1 == lastSmall){
            curr++;
            lastSmall= v[i];
        }else if(v[i]-1 != lastSmall){
            curr= 1;
            lastSmall = v[i];
        }
        longest = max(longest ,curr);
    }
    return longest;
}

int longestConSubSeq(vector<int> v){
    int n = v.size();
    int longest =0;
    int curr=0;

    unordered_set<int> st;
    for(int i=0 ; i<n ; i++){
        st.insert(v[i]);
    }

    for(int it : st){
       
        if(st.find(it-1) == st.end()){
            curr=1;
            int next = it+1;
            while(st.find(next) != st.end()){
                curr++;
                next++;
            }

        }
        longest = max(longest,curr);

    }

    return longest;
}

int main()
{
    vector<int> v = {100, 4, 200,3, 1, 2,101,6,103,5};

    cout << " longest consecutive subseq " << endl;
    cout << longestConSubSeq_brute(v)<< endl;
    cout << longestConSubSeq_better(v)<< endl;
    cout << longestConSubSeq(v)<< endl;

    return 0;
}