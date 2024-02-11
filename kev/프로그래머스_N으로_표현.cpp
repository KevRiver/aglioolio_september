#include <iostream>
#include <vector>
#include <set>

using namespace std;

int pow(int n, int exp){
    if(exp == 0)
        return 1;
    
    int ret = n;
    for(int i = 1; i < exp; ++i)
        ret *= n;
    
    return ret;
}

vector<set<int>> ss(8 + 1);

int main(){
    int N = 5;
    int t = 0;
    for(int i = 0; i < 8; ++i){
        t += pow(10, i);
        ss[i + 1].insert(N * t);
        ss[i + 1].insert(i + 1);
    }

    for(const auto& s: ss){
        for(int e: s){
            cout << e << '\n';
        }
    }

    return 0;
}