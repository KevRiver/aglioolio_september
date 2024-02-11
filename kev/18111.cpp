#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> ground(N, vector<int>(M));
    int min_h = 257;
    int max_h = -1;
    for(int i=0; i<N; ++i){
        for(int j=0; j<M; ++j){
            int h; cin >> h;
            ground[i][j] = h;
            min_h = min(h, min_h);
            max_h = max(h, max_h);
        }
    }

    int height;
    int min_time_spend = INT_MAX;
    for(int h = min_h; h <= max_h; ++h){
        int dig = 0;
        int fill = 0;
        for(int i=0; i<N; ++i){
            for(int j=0; j<M; ++j){
                int diff = h - ground[i][j];
                if(diff < 0) dig += -diff;
                else fill += diff;
            }
        }
        
        if(B + dig < fill) continue;

        int time_spend = dig*2 + fill;
        if(time_spend > min_time_spend) continue;

        min_time_spend = time_spend;
        height = h;
    }

    cout << min_time_spend << " " << height << '\n';
    
    return 0;
}