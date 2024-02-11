#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    unordered_map<string, string> um;
    um.reserve(n + 1);
    for(int i=0; i<n; ++i){
        string site, pass;
        cin >> site >> pass;
        um[site] = pass;
    }

    for(int i=0; i<m; ++i){
        string look; cin >> look;
        cout << um[look] << '\n';
    }

    return 0;
}