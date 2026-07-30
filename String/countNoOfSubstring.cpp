/*
You are given a string s and a positive integer k.
Return the number of substrings that contain exactly k distinct characters.

*/

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int atMostKDistinct(string s, int k){
    int n = s.length();
    int left =0; int ans =0;
    unordered_map<char,int> freq;
    for(int right =0;right<n;right++){
        freq[s[right]]++;
        if(freq.size()>k){
            freq[s[left]]--;
            if(freq[s[left]]==0) freq.erase(s[left]);
            left++;
        }
        ans+=(right-left+1);

    }

    return ans;
}

int countSubstrings(string s, int k) {
    // Exactly k = atMost(k) - atMost(k-1)
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main(){
    string s = "abcbaa";
    int k = 3;

    cout << "Count: " << countSubstrings(s, k) << endl;
    return 0;
}