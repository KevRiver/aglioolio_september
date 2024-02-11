#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int start = v[0].first;
    int end = v[0].second;
    int answer = 0;
    for(int i = 1; i < n; ++i){
        if(v[i].first <= end){
            end = max(end, v[i].second);
        } else {
            answer += end - start;
            start = v[i].first;
            end = v[i].second;
        }
    }
    answer += end - start;
    cout << answer << '\n';

    return 0;
}