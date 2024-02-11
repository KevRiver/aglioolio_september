#include <iostream>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int D, K;

pair<int, int> operator + (const pair<int, int>& l, const pair<int, int>& r){
    return {l.first + r.first, l.second + r.second};
}

void solve(){
    cin >> D >> K;
    pair<int, int> base_counter[3] = {{1, 0}, {0, 1}, {1, 1}};
    for(int d = 3; d <= D; ++d){
        base_counter[d % 3] = base_counter[(3 + d - 1) % 3] + base_counter[(3 + d - 2) % 3];
    }
    
    int a = base_counter[(D - 1) % 3].first;
    int b = base_counter[(D - 1) % 3].second;
    
    // k = a * x + b * y
    for(int y = 1; ; ++y){
        int r = K - b * y;
        if(r % a != 0) continue;
        int x = r / a;
        if(x > y) continue;
        cout << x << '\n';
        cout << y << '\n';
        break;       
    }

}

int main(){
    fastio
    solve();
    return 0;
}