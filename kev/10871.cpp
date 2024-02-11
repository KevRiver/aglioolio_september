#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x; cin >> n >> x;
    int cnt = 0;
    for(int i=0; i<n; ++i){
        int z; cin >> z;
        if(z < x) cout << z << " ";
    }
    cout << '\n';

    return 0;
}