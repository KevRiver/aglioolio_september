#include <iostream>
using namespace std;


// 어떤 수의 각 자리에서 인접한 자리와의 수 차이가 1인 수를 계단수라고한다
// 길이가 N인 계단 수의 개수를 1_000_000_000 으로 나눈 나머지를 구하라
// 0으로 시작하는 수는 포함하지 않는다
// N=1 일때 1,2,3,4,5,6,7,8,9는 계단수이다
// 마지막 자리가 숫자 n으로 끝나는 계단 수?

const int mod = 1000000000;
int dp[10][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i=1; i<10; ++i){
        dp[i][1] = 1;
    }
    for(int k = 2; k <= n; ++k){
        for(int i=0; i<10; ++i){
            if(i-1 >= 0) dp[i][k] += dp[i-1][k-1];
            if(i+1 < 10) dp[i][k] += dp[i+1][k-1];
            dp[i][k] = dp[i][k] < mod ? dp[i][k] : dp[i][k] % mod;
        }
    }
    int answer = 0;
    for(int i=0; i<10; ++i){
        answer += dp[i][n] % mod;
        answer %= mod;
    }
    cout << answer << '\n';    

    return 0;
}