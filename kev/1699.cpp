#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 21e8;

int cache[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    cache[0] = 0;
    for(int i = 1; i <= n; ++i) cache[i] = INF;

    for(int i = 1; i*i <= n; ++i){
        for(int j = i*i; j <= n; ++j){
            cache[j] = min(cache[j], cache[j - i*i] + 1);
        }
    }

    cout << cache[n] << '\n';

    return 0;
}