#include <iostream>

using namespace std;

int dp[5001];
const int mod = 1000000007;

int mod_add(int a, int b){
    return ((a % mod) + (b % mod)) % mod;
}

int mod_multiply(int a, int b){
    return ((a % mod) * (b % mod)) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0] = 1;
    dp[2] = 1;

    for(int i = 4; i <= 5000; i += 2){
        dp[i] = dp[i - 2];
        for(int j = 2; j <= i - 2; j += 2){
            dp[i] = mod_add(dp[i], mod_multiply(dp[j - 2], dp[i - j]));
        }
    }

    int T; cin >> T;
    for(int t = 0; t < T; ++t){
        int k; cin >> k;
        cout << dp[k] << '\n';
    }

    return 0;
}