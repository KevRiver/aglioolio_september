#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;

    cout << "nC2" << '\n';
    for(int i=1; i<=n-1; ++i){
        for(int j=i+1; j<=n; ++j){
            cout << i << " " << j << '\n';
        }
    }
    /*
    nC2
    1 2
    1 3
    1 4
    1 5
    2 3
    2 4
    2 5
    3 4
    3 5
    4 5
    */

    cout << "nC3" << '\n';
    for(int i=1; i<=n-2; ++i){
        for(int j=i+1; j<=n-1; ++j){
            for(int k=j+1; k<=n; ++k){
                cout << i << " " << j << " " << k << '\n';
            }
        }
    }
    cout << '\n';

    return 0;
}