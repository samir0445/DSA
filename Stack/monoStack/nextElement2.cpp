#include<iostream>
#include<vector>
#include<Stack>
#include<algorithm>
using namespace std;

/*
what is different from nextElemet-1 : in it array wasnt circular and array was containg unique element where else

where else nextELement-2 : has circular array and repated element is allowed

*/

// LOGIC(DONT KNOW if is it optimal or not-made by author)
/*
has it has circular property try to implemnt like this
give array [4 3 2 1]
so it is ciruclar try to implemnet same logic to

[4 3 2 1 4 3 2 1]

so here travel from back or first loop will give result of next element 1 
i take that same stack which has element after loop 1 and repeat it one more time so that it give me result for circular proprty

*/


vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            st.push(nums[i]);
        }
        // i can mane ans vector of 2*n size and just return first 1-n which actually contain my answerS
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                ans.push_back(-1);
            } else {
                while (!st.empty() && st.top() <= nums[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    ans.push_back(-1);
                } else {

                    ans.push_back(st.top());
                }
            }
            st.push(nums[i]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

int main(){
    vector<int> v = {6,5,4,3,2,1};
    for(int it : v){
        cout<< it << " ,";
    }cout<<endl;
    cout<<"Next Greater Element while repeating number and having circular array"<<endl;

    vector <int> ans = nextGreaterElements(v);
    for(int it : ans){
        cout<< it << " ,";
    }cout<<endl;



    return 0;
}