#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000];

int main(){

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    vector<int> lis = {a[0]};
    int len = 1;
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        if(lis.back() < a[i]){
            lis.push_back(a[i]);
            dp[i] = ++len;
        } else{
            int pos = lower_bound(begin(lis), end(lis), a[i]) - begin(lis);
            lis[pos] = a[i];
            dp[i] = pos + 1;            
        }
    }

    cout << len << '\n';
    vector<int> seq;
    for(int i = n - 1; i >= 0; --i){
        if(dp[i] == len){
            seq.push_back(a[i]);
            --len;
        }
    }
    for(auto it = seq.rbegin(); it != seq.rend(); ++it){
        cout << *it << " ";
    }
    cout << '\n';

    return 0;
}