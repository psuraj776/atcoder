#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin>>N;
    cin>>S;
    int ans=0;
    int count_1=0;
    for(int i=0;i<N;i++) {
        if(S[i]=='1') count_1++;
    }
    int temp_ans=0;
    for(int i=0;i<N;i++) {
        if(S[i]=='1') temp_ans++;
        else ans += min(temp_ans, count_1-temp_ans);
    }
    cout << ans;
    return 0;
}
