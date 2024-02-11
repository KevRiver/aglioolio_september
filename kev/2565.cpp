#include <iostream>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<pii> wires(n);
    for(int i = 0; i < n; ++i)
        cin >> wires[i].first >> wires[i].second;
    
    sort(begin(wires), end(wires));

    vector<int> lis;
    int t = 0;
    for(int i = 0; i < n; ++i){
        int b = wires[i].second;
        if(lis.empty() || lis.back() < b){
            lis.push_back(b);
            ++t;
        } else{
            auto it = lower_bound(begin(lis), end(lis), b);
            *it = b;
        }
    }

    cout << n - t << '\n';

    return 0;
}