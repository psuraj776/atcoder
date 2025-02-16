#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,K;
    cin>>N>>K;
    vector<int> vec(N);
    for(int i=0;i<N;i++) {
        int x;
        cin>>x;
        vec[i]=x;
    }
    
    int M=vec[0];
    /*
    vec = {3, 4, 6, 7, 12}
    */
    for(int i=1;i<N;i++){
        if(M<vec[i]) M=vec[i];
    }
    
    vector<int> occurance(M+1);
    /*
    of size max+1 of vec here it is 12+1
    it holds the occurance of each element in vec
    occurance = {0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1}
    */
    for(int i=0;i<N;i++) {
        occurance[vec[i]]++;
    }
    
    /*
    of size max+1 again
    it holds how many numbers are divisble by index(from 1 to M)
    divisro = {0, 5, 0, 3, 2, 0, 2, 1, 0, 0, 0, 0, 1}
    */
    vector<int> divisor(M+1);
    for(int i=1;i<=M;i++) {
        for(int j=i;j<=M;j+=i){
            divisor[i] += occurance[j];
        }
    }
    /*
    ans of size max+1 
    it holds gcd of that particular number(index) keeping the K contraints in mind
    */
    vector<int> ans(M+1);
    for(int i=1;i<=M;i++){
        if(divisor[i]<K) continue;
        for(int j=i;j<=M;j+=i){
            ans[j]=max(ans[j], i);
        }
    }
    
    for(auto a:vec) cout<<ans[a]<<endl;
    return 0;
}
