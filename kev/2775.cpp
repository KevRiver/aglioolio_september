#include <iostream>
using namespace std;

int p[15][15];

void solve(){
    int k; cin >> k; // floor
    int n; cin >> n; // room
    cout << p[k][n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // a-1 층의 1~b호까지의 사람 수의 합만큼 데려와 살아야함
    for(int i=1; i < 15; ++i){
        p[0][i] = i;
    }

    for(int k=1; k < 15; ++k){
        for(int n=1; n < 15; ++n){
            p[k][n] = p[k][n-1] + p[k-1][n];
        }
    }

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}