#include <iostream>

using namespace std;

// height 2 고정
// dp[w] = 2*w 직사각형을 2*1, 1*2, 2*2 사각형으로 채우는 경우의 수
int dp[1001];
const int mod = 10007;

int main(){
    int n; cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    for(int w=2; w<=n; ++w){
        dp[w] = ((dp[w-1]%mod) + ((dp[w-2]%mod)*2)%mod)%mod;
    }
    cout << dp[n] << '\n';
}