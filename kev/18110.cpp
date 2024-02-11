#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    if(n == 0){
        cout << 0 << '\n';
        return 0;
    }

    vector<int> seq(n);
    for(int i=0; i<n; ++i) cin >> seq[i];
    
    sort(begin(seq), end(seq));
    int k = round((double)n * 0.15);
    
    int sum = 0;
    for(int i=k; i < n-k; ++i){
        sum += seq[i];
    }

    int avg = round((double)sum/(n-k*2));
    cout << avg << '\n';

    return 0;
}