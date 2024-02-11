#include <iostream>
#include <vector>

using namespace std;

int dp[1000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> seq(N);
    for(auto& e: seq)
        cin >> e;

    int answer = 0;
    for(int i = 0; i < N; ++i){
        dp[i] = 1;
        for(int j = 0; j < i; ++j){
            if(seq[j] <= seq[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';

    return 0;
}