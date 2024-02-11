#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <algorithm>
using namespace std;

const int INF = INT_MAX/2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> dp(k+1, INF);
    dp[0] = 0;
    set<int> coins;
    for(int i=0; i<n; ++i){
        int c; cin >> c;
        coins.insert(c);
    }
    for(auto it=coins.begin(); it != coins.end(); ++it){
        int c = *it;
        for(int i=c; i <= k; ++i){
            dp[i] = min(dp[i-c] + 1, dp[i]);
        }
    }
    if(dp[k] == INF) cout << -1 << '\n';
    else cout << dp[k] << '\n';

    return 0;
}