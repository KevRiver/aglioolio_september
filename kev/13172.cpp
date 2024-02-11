#include <iostream>
#include <map>
#include <vector>
#include <functional>
using namespace std;

#define pii pair<int, int>
#define ll long long
const ll MOD = 1'000'000'007;

int gcd(int x, int y){
    if(y>x){
        int tmp = x; 
        x = y; 
        y = tmp;
    }
    return x%y == 0 ? y : gcd(y, x%y);
}

ll f(ll x, ll k){
    // x^k
    if(k == 1) return x;
    if(k%2 == 1) return x * f(x, k-1) % MOD;
    ll y = f(x, k/2);
    return y*y%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> m;
    vector<pii> v(m);
    for(int i=0; i<m; ++i){
        cin >> v[i].first >> v[i].second;
    }

    ll sum = 0;
    for(const pii& e: v){
        int n = e.first;
        int s = e.second;
        int g = gcd(n, s);
        n /= g;
        s /= g;
        sum += (ll)s * f(n, MOD-2) % MOD;
        sum %= MOD; 
    }
    cout << sum << '\n';

    return 0;
}