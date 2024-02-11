#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].first >> v[i].second;
    }
    
    int min_mag = INT_MAX;
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            int dy = v[i].first - v[j].first;
            int dx = v[i].second - v[j].second;
            min_mag = min(min_mag, (dy*dy) + (dx*dx));
        }
    }

    cout << min_mag << '\n';

    return 0;
}