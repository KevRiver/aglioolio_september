#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n); for(int& e: v) cin >> e;

    vector<int> lis;
    lis.push_back(v[0]);
    int len = 1;
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        if(lis.back() < v[i]){
            lis.push_back(v[i]);
            dp[i] = ++len;
        } else{
            int pos = lower_bound(begin(lis), end(lis), v[i]) - begin(lis);
            lis[pos] = v[i];
            dp[i] = pos + 1;
        }
    }

    cout << len << '\n';
    vector<int> seq;
    for(int i = n-1; i >= 0; --i){
        if(dp[i] == len){
            seq.push_back(v[i]);
            --len;
        }
    }
    for(auto it = seq.rbegin(); it != seq.rend(); ++it){
        cout << *it << " ";
    }
    cout << '\n';

    return 0;
}