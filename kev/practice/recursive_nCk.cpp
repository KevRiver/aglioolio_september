#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(){

    int n; cin >> n;
    int k; cin >> k;
    vector<int> res;
    function<void(int)> nck = [&](int f){
        if(res.size() == k){
            for(int e: res){
                cout << e << " ";
            }
            cout << '\n';
            return;
        }
        for(int i = f; i <= n; ++i){
            res.push_back(i);
            nck(i + 1);
            res.pop_back();
        }
    };
    nck(1);
    
    return 0;
}