#include <iostream>
#include <map>
#include <functional>

using namespace std;

#define ll long long
const ll mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    
    unordered_map<ll, ll> m;
    m[0] = 0;
    m[1] = 1;
    m[2] = 1;

    function<ll(ll)> fibo = [&](ll nth){
        if(m.find(nth) != m.end()) 
            return m[nth];

        ll x;
        if(nth % 2 == 0){
            ll a = fibo(nth/2)%mod;
            ll b = fibo(nth/2 - 1)%mod;
            ll c = fibo(nth/2 + 1)%mod;
            
            x = (a*((b+c)%mod))%mod;

        } else {
            ll a = fibo((nth-1)/2)%mod;
            ll b = fibo((nth+1)/2)%mod;

            x = ((a*a)%mod + (b*b)%mod)%mod;
        }

        m[nth] = x;
        return x;
    };

    ll answer = fibo(n);
    cout << answer << '\n';

    return 0;
}