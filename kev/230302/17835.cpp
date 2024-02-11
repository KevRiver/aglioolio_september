#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N, M, K;
void solve(){
    cin >> N >> M >> K;
    
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INT_MAX / 2));
    for(int i = 1; i < N + 1; ++i) dist[i][i] = 0;
    
    for(int i = 0; i < M; ++i){
        int src, dest, cost;
        cin >> src >> dest >> cost;
        dist[src][dest] = cost;
    }

    vector<int> places(K);
    for(int k = 0; k < K; ++k)
        cin >> places[k];
    
    
    for(int k = 1; k < N + 1; ++k){
        for(int i = 1; i < N + 1; ++i){
            for(int j = 1; j < N + 1; ++j){
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int max_dist_city;
    int max_dist = -1;
    for(int i = 1; i < N + 1; ++i){
        int cur_dist = INT_MAX;
        for(const auto& place: places){
            cur_dist = min(dist[i][place], cur_dist);
        }
        if(max_dist >= cur_dist) continue;
        max_dist = cur_dist;
        max_dist_city = i;
    }

    cout << max_dist_city << "\n";
    cout << max_dist << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}