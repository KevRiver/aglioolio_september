#include <iostream>
#include <algorithm>
using namespace std;

const int INF = (int)21e9;
int dp[50001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for(int i=0; i<=n; ++i) dp[i] = INF;
    dp[0] = 0;
    for(int i=1; i*i<=n; ++i){
        for(int j=i*i; j <= n; ++j){
            dp[j] = min(dp[j], dp[j-i*i] + 1);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}