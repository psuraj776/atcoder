#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;


int main() {
    unordered_map<int, set<int>> ump;
    int N,M;
    cin>>N>>M;
    int res=0;
    for(int i=0;i<M;i++) {
        int from,to;
        cin>>from>>to;
        if(from == to){
            res+=1;
            continue;
        }
        if(ump.find(from) == ump.end()) {
            ump[from].insert(to);
            ump[to].insert(from);
        }
        else {
            if(ump[from].find(to) != ump[from].end()) {
                res += 1;
            }
            else{
                ump[from].insert(to);
                ump[to].insert(from);
            }
        }
    }
    
    cout<<res;
    return 0;
}
