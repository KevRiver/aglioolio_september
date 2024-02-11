#include <iostream>

using namespace std;

int dp[31][31];

int main(){
    // nCm 구하기 문제
    for(int i = 1; i <= 30; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    int t; cin >> t;
    for(int r = 0; r < t; ++r){
        int n; cin >> n;
        int m; cin >> m;

        cout << dp[m][n] << '\n';
    }

    return 0;
}