#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    string s="AABAAABBAEDCCCD";
    vector<int> idx;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B') idx.push_back(i);
    }
    int res=0;
    for(int i=0;i<idx.size();i++){
        int left=idx[i]-1;
        int right=idx[i]+1;
        while(left>=0 && right<s.size()){
            if(s[left]=='A' && s[right]=='C') res++;
            left--;
            right++;
        }
    }
    cout<<res;
    return 0;
}
