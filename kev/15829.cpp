#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const ll mod = 1234567891;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    string str; cin >> str;
    ll h = 0;
    ll r = 1;
    for(int i=0; i<n; ++i){
        ll a = (str[i] - 'a') + 1;
        h += a * r % mod;
        r = r * 31 % mod;
        h %= mod;
    }
    cout << h << '\n';

    return 0;
}