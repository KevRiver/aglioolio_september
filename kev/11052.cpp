#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(){
    // 돈을 최대한 많이 지불해서 N개의 카드팩을 산다

    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(j - i < 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - i] + p[i]);
            // 중복하여 카드팩을 구매할 수 있으므로, dp[i][j-i]와 비교한다
            // 중복 카드팩을 구매할 수 없으면 dp[i - 1][j - i]와 비교한다
        }
    }

    cout << dp[n][n] << '\n';

    return 0;
}