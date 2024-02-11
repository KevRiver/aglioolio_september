#include <iostream>
#include <algorithm>
using namespace std;

int grid[100'000][3];
int mx[3];
int mn[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; ++i){
        cin >> grid[i][0] >> grid[i][1] >> grid[i][2];
    }
    
    mx[0] = mn[0] = grid[0][0];
    mx[1] = mn[1] = grid[0][1];
    mx[2] = mn[2] = grid[0][2];

    for(int i=1; i<=N; ++i){
        int x = max(mx[0], mx[1]) + grid[i][0];
        int y = max(max(mx[0], mx[1]), mx[2]) + grid[i][1];
        int z = max(mx[1], mx[2]) + grid[i][2];
        mx[0] = x; mx[1] = y; mx[2] = z;

        x = min(mn[0], mn[1]) + grid[i][0];
        y = min(min(mn[0], mn[1]), mn[2]) + grid[i][1];
        z = min(mn[1], mn[2]) + grid[i][2];
        mn[0] = x; mn[1] = y; mn[2] = z;
    }

    int a = -1, b = 1'000'000;
    for(int j=0; j<3; ++j){
        a = max(a, mx[j]);
        b = min(b, mn[j]);
    }
    cout << a << " " << b << '\n';

    return 0;
}