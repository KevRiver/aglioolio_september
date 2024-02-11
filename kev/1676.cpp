#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>

int main(){
    int n; cin >> n;
    
    vector<pii> v(n+1, {0, 0});
    
    for(int i = 2; i <= n; i *= 2){
        for(int j=1; i*j <= n; ++j){
            v[i*j].first++;
        }
    }
    for(int i = 5; i <= n; i *= 5){
        for(int j=1; i*j <= n; ++j){
            v[i*j].second++;
        }
    }

    int two = 0;
    int five = 0;
    for(int i=1; i<=n; ++i){
        two += v[i].first;
        five += v[i].second;
    }

    int answer = min(two, five);

    cout << answer << '\n';

    return 0;
}